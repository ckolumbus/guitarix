/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose, Steve Poskitt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */

////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gxtape_st.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "gxtape_st.cc"    // dsp class generated by faust -> dsp2cc
#ifndef __SSE__
#include "noiser.cc"
#endif

////////////////////////////// PLUG-IN CLASS ///////////////////////////


class Gxtape_st
{
private:
  // internal stuff
  float*                       output0;
  float*                       input0;
  float*                       output1;
  float*                       input1;
  float*                       meterlevel;
  PluginLV2*                   tape;
#ifndef __SSE__
  PluginLV2*                   wn;
#endif
public:

  inline void run_dsp_stereo(uint32_t n_samples);
  inline void connect_stereo(uint32_t port,void* data);
  inline void init_dsp_stereo(uint32_t rate);
  inline void connect_all_stereo_ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  Gxtape_st();
  ~Gxtape_st();
};

// constructor
Gxtape_st::Gxtape_st() :
  output0(NULL),
  input0(NULL),
  output1(NULL),
  input1(NULL),
  tape(gxtape_st::plugin()) {};

// destructor
Gxtape_st::~Gxtape_st()
{
  // just to be sure the plug have given free the allocated mem
 
 // it didn't hurd if the mem is already given free by clean_up()
  //tape->activate_plugin(false, tape);
  // delete DSP class
  tape->delete_instance(tape);
};

////////////////////////////// PLUG-IN CLASS  FUNCTIONS ////////////////

void Gxtape_st::init_dsp_stereo(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
#ifndef __SSE__
  wn = noiser::plugin();
  wn->set_samplerate(rate, wn);
#endif
  tape->set_samplerate(rate, tape); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gxtape_st::connect_stereo(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT_L:
      output0 = static_cast<float*>(data);
      break;
    case EFFECTS_OUTPUT_R:
      output1 = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT_L:
      input0 = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT_R:
      input1 = static_cast<float*>(data);
      break;
/*    case METERLEVEL:
      meterlevel = static_cast<float*>(data);
      break;
 */   default:
      break;
    }
}

void Gxtape_st::activate_f()
{
  // allocate the internal DSP mem
//  tape->activate_plugin(true, tape);
}

void Gxtape_st::clean_up()
{
#ifndef __SSE__
  wn->delete_instance(wn);;
#endif
  // delete the internal DSP mem
 // tape->activate_plugin(false, tape);
}

void Gxtape_st::run_dsp_stereo(uint32_t n_samples)
{
#ifndef __SSE__
  wn->stereo_audio(static_cast<int>(n_samples), input0,
                         input1, output0,output1,  wn);;
#endif
  tape->stereo_audio(static_cast<int>(n_samples), input0,
                        input1, output0,output1, tape);	

}

void Gxtape_st::connect_all_stereo_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_stereo(port,data); 
  // connect the Ports used by the DSP class
  tape->connect_ports(port,  data, tape);
}

///////////////////////////// LV2 defines //////////////////////////////

static LV2_Handle
instantiate(const LV2_Descriptor*     descriptor,
            double                    rate,
            const char*               bundle_path,
            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gxtape_st *self = new Gxtape_st();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_stereo((uint32_t)rate);

  return (LV2_Handle)self;
}

static void
connect_port(LV2_Handle instance,
             uint32_t   port,
             void*      data)
{
  // connect all ports
  static_cast<Gxtape_st*>(instance)->connect_all_stereo_ports(port, data);
}

static void
activate(LV2_Handle instance)
{
  // allocate needed mem
  //static_cast<Gxtape_st*>(instance)->activate_f();
}

static void
run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gxtape_st*>(instance)->run_dsp_stereo(n_samples);
}

static void
cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gxtape_st* self = static_cast<Gxtape_st*>(instance);
  self->clean_up();
  delete self;
}

///////////////////////////// LV2 DESCRIPTOR ///////////////////////////
static const LV2_Descriptor descriptor =
{
  GXPLUGIN_URI "#tape",
  instantiate,
  connect_port,
  activate,
  run,
  NULL,
  cleanup,
  NULL
};

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////