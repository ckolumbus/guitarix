// generated from file '../src/LV2/faust/gxamp6_stereo.dsp' by dsp2cc:
// Code generated with Faust 0.9.46 (http://faust.grame.fr)

#include "valve.h"

namespace gxamp6_stereo {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fVec0[2];
	double 	fConst19;
	double 	fRec5[2];
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec6[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec8[2];
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fVec1[2];
	double 	fConst29;
	double 	fRec21[2];
	double 	fRec20[2];
	double 	fRec19[3];
	double 	fRec18[3];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT	*fslider2_;
	double 	fRec22[2];
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fVec2[2];
	double 	fConst33;
	double 	fRec23[2];
	double 	fRec17[2];
	double 	fConst34;
	double 	fConst35;
	double 	fRec16[2];
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fVec3[2];
	double 	fConst39;
	double 	fRec26[2];
	double 	fRec25[2];
	double 	fRec24[2];
	double 	fRec15[2];
	double 	fRec14[2];
	double 	fVec4[2];
	double 	fRec27[2];
	double 	fRec13[2];
	double 	fRec12[2];
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fVec5[2];
	double 	fConst43;
	double 	fRec30[2];
	double 	fRec29[2];
	double 	fRec28[2];
	double 	fRec11[2];
	double 	fVec6[2];
	double 	fRec31[2];
	double 	fRec10[2];
	double 	fRec9[2];
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT	*fslider3_;
	double 	fRec34[2];
	int 	IOTA;
	double 	fVec7[32768];
	int 	iConst44;
	double 	fRec33[2];
	double 	fConst45;
	double 	fRec32[2];
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fConst60;
	double 	fConst61;
	double 	fConst62;
	double 	fConst63;
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;
	double 	fConst68;
	double 	fConst69;
	double 	fConst70;
	double 	fConst71;
	double 	fConst72;
	double 	fConst73;
	double 	fConst74;
	double 	fConst75;
	double 	fRec42[3];
	double 	fVec8[2];
	double 	fConst76;
	double 	fRec41[2];
	double 	fConst77;
	double 	fRec40[2];
	double 	fRec39[3];
	double 	fVec9[2];
	double 	fConst78;
	double 	fConst79;
	double 	fRec38[2];
	double 	fRec37[3];
	double 	fConst80;
	double 	fRec36[3];
	double 	fConst81;
	double 	fConst82;
	double 	fConst83;
	double 	fConst84;
	double 	fRec46[2];
	double 	fRec45[3];
	double 	fVec10[2];
	double 	fConst85;
	double 	fConst86;
	double 	fRec44[2];
	double 	fRec43[3];
	double 	fConst87;
	double 	fConst88;
	double 	fConst89;
	double 	fConst90;
	double 	fRec50[2];
	double 	fRec49[3];
	double 	fConst91;
	double 	fRec48[3];
	double 	fRec47[3];
	double 	fRec52[2];
	double 	fRec51[3];
	double 	fVec11[2];
	double 	fRec35[2];
	double 	fVec12[2];
	double 	fRec7[2];
	double 	fRec4[2];
	double 	fConst92;
	double 	fRec3[2];
	double 	fVec13[2];
	double 	fRec55[2];
	double 	fRec54[2];
	double 	fRec53[2];
	double 	fVec14[3];
	double 	fConst93;
	double 	fConst94;
	double 	fRec2[3];
	double 	fConst95;
	double 	fConst96;
	double 	fRec1[3];
	double 	fConst97;
	double 	fConst98;
	double 	fRec0[3];
	double 	fVec15[2];
	double 	fRec74[2];
	double 	fRec73[2];
	double 	fRec72[3];
	double 	fRec71[3];
	double 	fVec16[2];
	double 	fRec75[2];
	double 	fRec70[2];
	double 	fRec69[2];
	double 	fVec17[2];
	double 	fRec78[2];
	double 	fRec77[2];
	double 	fRec76[2];
	double 	fRec68[2];
	double 	fRec67[2];
	double 	fVec18[2];
	double 	fRec79[2];
	double 	fRec66[2];
	double 	fRec65[2];
	double 	fVec19[2];
	double 	fRec82[2];
	double 	fRec81[2];
	double 	fRec80[2];
	double 	fRec64[2];
	double 	fVec20[2];
	double 	fRec83[2];
	double 	fRec63[2];
	double 	fRec62[2];
	double 	fRec86[2];
	double 	fVec21[32768];
	double 	fRec85[2];
	double 	fRec84[2];
	double 	fRec94[3];
	double 	fVec22[2];
	double 	fRec93[2];
	double 	fRec92[2];
	double 	fRec91[3];
	double 	fVec23[2];
	double 	fRec90[2];
	double 	fRec89[3];
	double 	fRec88[3];
	double 	fRec98[2];
	double 	fRec97[3];
	double 	fVec24[2];
	double 	fRec96[2];
	double 	fRec95[3];
	double 	fRec102[2];
	double 	fRec101[3];
	double 	fRec100[3];
	double 	fRec99[3];
	double 	fRec104[2];
	double 	fRec103[3];
	double 	fVec25[2];
	double 	fRec87[2];
	double 	fVec26[2];
	double 	fRec61[2];
	double 	fVec27[2];
	double 	fRec105[2];
	double 	fRec60[2];
	double 	fRec59[2];
	double 	fVec28[2];
	double 	fRec108[2];
	double 	fRec107[2];
	double 	fRec106[2];
	double 	fVec29[3];
	double 	fRec58[3];
	double 	fRec57[3];
	double 	fRec56[3];
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, float *input0, float *input1, float *output0, float *output1);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, float *input0, float *input1, float *output0, float *output1, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "pre 6DJ8/ push-pull 6V6";
	name = N_("pre 6DJ8/ push-pull 6V6");
	mono_audio = 0;
	stereo_audio = compute_static;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec21[i] = 0;
	for (int i=0; i<2; i++) fRec20[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<3; i++) fRec18[i] = 0;
	for (int i=0; i<2; i++) fRec22[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec23[i] = 0;
	for (int i=0; i<2; i++) fRec17[i] = 0;
	for (int i=0; i<2; i++) fRec16[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec26[i] = 0;
	for (int i=0; i<2; i++) fRec25[i] = 0;
	for (int i=0; i<2; i++) fRec24[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fVec4[i] = 0;
	for (int i=0; i<2; i++) fRec27[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<2; i++) fRec12[i] = 0;
	for (int i=0; i<2; i++) fVec5[i] = 0;
	for (int i=0; i<2; i++) fRec30[i] = 0;
	for (int i=0; i<2; i++) fRec29[i] = 0;
	for (int i=0; i<2; i++) fRec28[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<2; i++) fVec6[i] = 0;
	for (int i=0; i<2; i++) fRec31[i] = 0;
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fRec34[i] = 0;
	for (int i=0; i<32768; i++) fVec7[i] = 0;
	for (int i=0; i<2; i++) fRec33[i] = 0;
	for (int i=0; i<2; i++) fRec32[i] = 0;
	for (int i=0; i<3; i++) fRec42[i] = 0;
	for (int i=0; i<2; i++) fVec8[i] = 0;
	for (int i=0; i<2; i++) fRec41[i] = 0;
	for (int i=0; i<2; i++) fRec40[i] = 0;
	for (int i=0; i<3; i++) fRec39[i] = 0;
	for (int i=0; i<2; i++) fVec9[i] = 0;
	for (int i=0; i<2; i++) fRec38[i] = 0;
	for (int i=0; i<3; i++) fRec37[i] = 0;
	for (int i=0; i<3; i++) fRec36[i] = 0;
	for (int i=0; i<2; i++) fRec46[i] = 0;
	for (int i=0; i<3; i++) fRec45[i] = 0;
	for (int i=0; i<2; i++) fVec10[i] = 0;
	for (int i=0; i<2; i++) fRec44[i] = 0;
	for (int i=0; i<3; i++) fRec43[i] = 0;
	for (int i=0; i<2; i++) fRec50[i] = 0;
	for (int i=0; i<3; i++) fRec49[i] = 0;
	for (int i=0; i<3; i++) fRec48[i] = 0;
	for (int i=0; i<3; i++) fRec47[i] = 0;
	for (int i=0; i<2; i++) fRec52[i] = 0;
	for (int i=0; i<3; i++) fRec51[i] = 0;
	for (int i=0; i<2; i++) fVec11[i] = 0;
	for (int i=0; i<2; i++) fRec35[i] = 0;
	for (int i=0; i<2; i++) fVec12[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<2; i++) fVec13[i] = 0;
	for (int i=0; i<2; i++) fRec55[i] = 0;
	for (int i=0; i<2; i++) fRec54[i] = 0;
	for (int i=0; i<2; i++) fRec53[i] = 0;
	for (int i=0; i<3; i++) fVec14[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fVec15[i] = 0;
	for (int i=0; i<2; i++) fRec74[i] = 0;
	for (int i=0; i<2; i++) fRec73[i] = 0;
	for (int i=0; i<3; i++) fRec72[i] = 0;
	for (int i=0; i<3; i++) fRec71[i] = 0;
	for (int i=0; i<2; i++) fVec16[i] = 0;
	for (int i=0; i<2; i++) fRec75[i] = 0;
	for (int i=0; i<2; i++) fRec70[i] = 0;
	for (int i=0; i<2; i++) fRec69[i] = 0;
	for (int i=0; i<2; i++) fVec17[i] = 0;
	for (int i=0; i<2; i++) fRec78[i] = 0;
	for (int i=0; i<2; i++) fRec77[i] = 0;
	for (int i=0; i<2; i++) fRec76[i] = 0;
	for (int i=0; i<2; i++) fRec68[i] = 0;
	for (int i=0; i<2; i++) fRec67[i] = 0;
	for (int i=0; i<2; i++) fVec18[i] = 0;
	for (int i=0; i<2; i++) fRec79[i] = 0;
	for (int i=0; i<2; i++) fRec66[i] = 0;
	for (int i=0; i<2; i++) fRec65[i] = 0;
	for (int i=0; i<2; i++) fVec19[i] = 0;
	for (int i=0; i<2; i++) fRec82[i] = 0;
	for (int i=0; i<2; i++) fRec81[i] = 0;
	for (int i=0; i<2; i++) fRec80[i] = 0;
	for (int i=0; i<2; i++) fRec64[i] = 0;
	for (int i=0; i<2; i++) fVec20[i] = 0;
	for (int i=0; i<2; i++) fRec83[i] = 0;
	for (int i=0; i<2; i++) fRec63[i] = 0;
	for (int i=0; i<2; i++) fRec62[i] = 0;
	for (int i=0; i<2; i++) fRec86[i] = 0;
	for (int i=0; i<32768; i++) fVec21[i] = 0;
	for (int i=0; i<2; i++) fRec85[i] = 0;
	for (int i=0; i<2; i++) fRec84[i] = 0;
	for (int i=0; i<3; i++) fRec94[i] = 0;
	for (int i=0; i<2; i++) fVec22[i] = 0;
	for (int i=0; i<2; i++) fRec93[i] = 0;
	for (int i=0; i<2; i++) fRec92[i] = 0;
	for (int i=0; i<3; i++) fRec91[i] = 0;
	for (int i=0; i<2; i++) fVec23[i] = 0;
	for (int i=0; i<2; i++) fRec90[i] = 0;
	for (int i=0; i<3; i++) fRec89[i] = 0;
	for (int i=0; i<3; i++) fRec88[i] = 0;
	for (int i=0; i<2; i++) fRec98[i] = 0;
	for (int i=0; i<3; i++) fRec97[i] = 0;
	for (int i=0; i<2; i++) fVec24[i] = 0;
	for (int i=0; i<2; i++) fRec96[i] = 0;
	for (int i=0; i<3; i++) fRec95[i] = 0;
	for (int i=0; i<2; i++) fRec102[i] = 0;
	for (int i=0; i<3; i++) fRec101[i] = 0;
	for (int i=0; i<3; i++) fRec100[i] = 0;
	for (int i=0; i<3; i++) fRec99[i] = 0;
	for (int i=0; i<2; i++) fRec104[i] = 0;
	for (int i=0; i<3; i++) fRec103[i] = 0;
	for (int i=0; i<2; i++) fVec25[i] = 0;
	for (int i=0; i<2; i++) fRec87[i] = 0;
	for (int i=0; i<2; i++) fVec26[i] = 0;
	for (int i=0; i<2; i++) fRec61[i] = 0;
	for (int i=0; i<2; i++) fVec27[i] = 0;
	for (int i=0; i<2; i++) fRec105[i] = 0;
	for (int i=0; i<2; i++) fRec60[i] = 0;
	for (int i=0; i<2; i++) fRec59[i] = 0;
	for (int i=0; i<2; i++) fVec28[i] = 0;
	for (int i=0; i<2; i++) fRec108[i] = 0;
	for (int i=0; i<2; i++) fRec107[i] = 0;
	for (int i=0; i<2; i++) fRec106[i] = 0;
	for (int i=0; i<3; i++) fVec29[i] = 0;
	for (int i=0; i<3; i++) fRec58[i] = 0;
	for (int i=0; i<3; i++) fRec57[i] = 0;
	for (int i=0; i<3; i++) fRec56[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = (31704.95306002819 / iConst0);
	fConst2 = (2 * cos(fConst1));
	fConst3 = (0.026178010471204185 * sin(fConst1));
	fConst4 = (fConst3 - 1);
	fConst5 = (49574.33207364693 / iConst0);
	fConst6 = (2 * cos(fConst5));
	fConst7 = (0.07042253521126761 * sin(fConst5));
	fConst8 = (fConst7 - 1);
	fConst9 = (60601.32228774711 / iConst0);
	fConst10 = (2 * cos(fConst9));
	fConst11 = (0.03546099290780142 * sin(fConst9));
	fConst12 = (fConst11 - 1);
	fConst13 = (1.0 / tan((97.38937226128358 / iConst0)));
	fConst14 = (1 + fConst13);
	fConst15 = (0 - ((1 - fConst13) / fConst14));
	fConst16 = (1.0 / tan((20517.741620594938 / iConst0)));
	fConst17 = (1 + fConst16);
	fConst18 = (0 - ((1 - fConst16) / fConst17));
	fConst19 = (1.0 / fConst17);
	fConst20 = tan((37699.11184307752 / iConst0));
	fConst21 = (2 * (1 - (1.0 / faustpower<2>(fConst20))));
	fConst22 = (1.0 / fConst20);
	fConst23 = (1 + ((fConst22 - 0.7653668647301795) / fConst20));
	fConst24 = (1.0 / (1 + ((0.7653668647301795 + fConst22) / fConst20)));
	fConst25 = (1 + ((fConst22 - 1.8477590650225735) / fConst20));
	fConst26 = (1.0 / (1 + ((fConst22 + 1.8477590650225735) / fConst20)));
	fConst27 = (973.8937226128359 / iConst0);
	fConst28 = (1 - fConst27);
	fConst29 = (1.0 / (1 + fConst27));
	fConst30 = (1.0 / tan((270.1769682087222 / iConst0)));
	fConst31 = (1 + fConst30);
	fConst32 = (0 - ((1 - fConst30) / fConst31));
	fConst33 = (1.0 / fConst31);
	fConst34 = (0 - fConst13);
	fConst35 = (0.05 / fConst14);
	fConst36 = (1.0 / tan((414.6902302738527 / iConst0)));
	fConst37 = (1 + fConst36);
	fConst38 = (0 - ((1 - fConst36) / fConst37));
	fConst39 = (1.0 / fConst37);
	fConst40 = (1.0 / tan((609.4689747964198 / iConst0)));
	fConst41 = (1 + fConst40);
	fConst42 = (0 - ((1 - fConst40) / fConst41));
	fConst43 = (1.0 / fConst41);
	IOTA = 0;
	iConst44 = int((int((0.1111111111111111 * iConst0)) & 65535));
	fConst45 = (0.009000000000000008 / iConst0);
	fConst46 = tan((942.4777960769379 / iConst0));
	fConst47 = (1.0 / faustpower<2>(fConst46));
	fConst48 = (2 * (1 - fConst47));
	fConst49 = (1.0 / fConst46);
	fConst50 = (1 + ((fConst49 - 1.0) / fConst46));
	fConst51 = (1.0 / (1 + ((1.0 + fConst49) / fConst46)));
	fConst52 = tan((3769.9111843077517 / iConst0));
	fConst53 = (1.0 / faustpower<2>(fConst52));
	fConst54 = (2 * (1 - fConst53));
	fConst55 = (1.0 / fConst52);
	fConst56 = (1 + ((fConst55 - 1.0000000000000004) / fConst52));
	fConst57 = (1 + ((fConst55 + 1.0000000000000004) / fConst52));
	fConst58 = (1.0 / fConst57);
	fConst59 = (1 + fConst55);
	fConst60 = (0 - ((1 - fConst55) / fConst59));
	fConst61 = tan((10053.096491487338 / iConst0));
	fConst62 = (1.0 / faustpower<2>(fConst61));
	fConst63 = (2 * (1 - fConst62));
	fConst64 = (1.0 / fConst61);
	fConst65 = (1 + ((fConst64 - 1.0000000000000004) / fConst61));
	fConst66 = (1 + ((1.0000000000000004 + fConst64) / fConst61));
	fConst67 = (1.0 / fConst66);
	fConst68 = (1 + fConst64);
	fConst69 = (0 - ((1 - fConst64) / fConst68));
	fConst70 = tan((47123.8898038469 / iConst0));
	fConst71 = (2 * (1 - (1.0 / faustpower<2>(fConst70))));
	fConst72 = (1.0 / fConst70);
	fConst73 = (1 + ((fConst72 - 1.414213562373095) / fConst70));
	fConst74 = (1 + ((1.414213562373095 + fConst72) / fConst70));
	fConst75 = (1.0 / fConst74);
	fConst76 = (1.0 / (fConst14 * fConst74));
	fConst77 = (1.0 / fConst68);
	fConst78 = (0 - fConst55);
	fConst79 = (1.0 / (fConst59 * fConst66));
	fConst80 = (2 * (0 - fConst53));
	fConst81 = (1 + ((fConst49 - 1.0000000000000004) / fConst46));
	fConst82 = (1.0 / (1 + ((fConst49 + 1.0000000000000004) / fConst46)));
	fConst83 = (1 + fConst49);
	fConst84 = (0 - ((1 - fConst49) / fConst83));
	fConst85 = (0 - fConst49);
	fConst86 = (1.0 / (fConst83 * fConst57));
	fConst87 = (2 * (0 - fConst47));
	fConst88 = (1 + ((fConst55 - 1.0) / fConst52));
	fConst89 = (1.0 / (1 + ((1.0 + fConst55) / fConst52)));
	fConst90 = (0 - fConst64);
	fConst91 = (2 * (0 - fConst62));
	fConst92 = (0.025 / fConst14);
	fConst93 = (0 - fConst10);
	fConst94 = (1.0 / (1 + fConst11));
	fConst95 = (0 - fConst6);
	fConst96 = (1.0 / (1 + fConst7));
	fConst97 = (0 - fConst2);
	fConst98 = (1.0 / (1 + fConst3));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

inline void Dsp::compute(int count, float *input0, float *input1, float *output0, float *output1)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fslider2 (*fslider2_)
#define fslider3 (*fslider3_)
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * fslider0)));
	double 	fSlow1 = (1.000000000000001e-05 * fslider1);
	double 	fSlow2 = (0.0010000000000000009 * pow(10,(0.05 * fslider2)));
	double 	fSlow3 = fslider3;
	double 	fSlow4 = (1.25 * fSlow3);
	double 	fSlow5 = (2 * (fSlow3 - 0.5));
	double 	fSlow6 = (0.024937655860349125 * (1 - max(0, fSlow5)));
	double 	fSlow7 = pow(1e+01,(1.2 * fSlow3));
	double 	fSlow8 = (fConst82 * pow(1e+01,(2 * fSlow3)));
	double 	fSlow9 = pow(1e+01,(0.8 * fSlow3));
	double 	fSlow10 = (fConst82 * pow(1e+01,(0.9 * fSlow3)));
	double 	fSlow11 = (1 - max(0, (0 - fSlow5)));
	for (int i=0; i<count; i++) {
		double fTemp0 = (1e-15 + (0.0041 * fRec4[1]));
		fVec0[0] = fTemp0;
		fRec5[0] = ((fConst19 * (fVec0[0] + fVec0[1])) + (fConst18 * fRec5[1]));
		fRec6[0] = (fSlow0 + (0.999 * fRec6[1]));
		fRec8[0] = (fSlow1 + (0.999 * fRec8[1]));
		double fTemp1 = (1 - fRec8[0]);
		double fTemp2 = (double)input0[i];
		fVec1[0] = fTemp2;
		fRec21[0] = (fConst29 * ((fVec1[0] - fVec1[1]) + (fConst28 * fRec21[1])));
		fRec20[0] = (fConst29 * ((fRec21[0] - fRec21[1]) + (fConst28 * fRec20[1])));
		fRec19[0] = (fRec20[0] - (fConst26 * ((fConst25 * fRec19[2]) + (fConst21 * fRec19[1]))));
		fRec18[0] = ((fConst26 * (fRec19[2] + (fRec19[0] + (2 * fRec19[1])))) - (fConst24 * ((fConst23 * fRec18[2]) + (fConst21 * fRec18[1]))));
		fRec22[0] = (fSlow2 + (0.999 * fRec22[1]));
		double fTemp3 = (1e-15 + (0.027 * fRec17[1]));
		fVec2[0] = fTemp3;
		fRec23[0] = ((fConst33 * (fVec2[0] + fVec2[1])) + (fConst32 * fRec23[1]));
		fRec17[0] = (Ftube(TUBE_TABLE_6DJ8_68k, ((fRec23[0] + (fConst24 * (fRec22[0] * (fRec18[2] + (fRec18[0] + (2 * fRec18[1])))))) - 1.863945999999999)) - 60.96496296296296);
		fRec16[0] = ((fConst35 * ((fConst34 * fRec17[1]) + (fConst13 * fRec17[0]))) + (fConst15 * fRec16[1]));
		double fTemp4 = (1e-15 + (0.015 * fRec25[1]));
		fVec3[0] = fTemp4;
		fRec26[0] = ((fConst39 * (fVec3[0] + fVec3[1])) + (fConst38 * fRec26[1]));
		fRec25[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec26[0] + fRec15[1]) - 1.2716089999999989)) - 45.22606666666667);
		fRec24[0] = ((fConst35 * ((fConst34 * fRec25[1]) + (fConst13 * fRec25[0]))) + (fConst15 * fRec24[1]));
		fRec15[0] = ((0.6 * fRec24[0]) + fRec16[0]);
		fRec14[0] = ((fConst19 * (fRec15[0] + fRec15[1])) + (fConst18 * fRec14[1]));
		double fTemp5 = (1e-15 + (0.015 * fRec13[1]));
		fVec4[0] = fTemp5;
		fRec27[0] = ((fConst39 * (fVec4[0] + fVec4[1])) + (fConst38 * fRec27[1]));
		fRec13[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec27[0] + fRec14[0]) - 1.2716089999999989)) - 45.22606666666667);
		fRec12[0] = ((fConst35 * ((fConst34 * fRec13[1]) + (fConst13 * fRec13[0]))) + (fConst15 * fRec12[1]));
		double fTemp6 = (1e-15 + (0.0082 * fRec29[1]));
		fVec5[0] = fTemp6;
		fRec30[0] = ((fConst43 * (fVec5[0] + fVec5[1])) + (fConst42 * fRec30[1]));
		fRec29[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec30[0] + fRec11[1]) - 0.797042999999999)) - 32.799634146341475);
		fRec28[0] = ((fConst35 * ((fConst34 * fRec29[1]) + (fConst13 * fRec29[0]))) + (fConst15 * fRec28[1]));
		fRec11[0] = ((0.6 * fRec28[0]) + fRec12[0]);
		double fTemp7 = (1e-15 + (0.0082 * fRec10[1]));
		fVec6[0] = fTemp7;
		fRec31[0] = ((fConst43 * (fVec6[0] + fVec6[1])) + (fConst42 * fRec31[1]));
		fRec10[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec31[0] + fRec11[0]) - 0.797042999999999)) - 32.799634146341475);
		fRec9[0] = ((fConst35 * ((fConst34 * fRec10[1]) + (fConst13 * fRec10[0]))) + (fConst15 * fRec9[1]));
		double fTemp8 = (fRec9[0] * fTemp1);
		double fTemp9 = (fRec9[0] * fRec8[0]);
		double fTemp10 = fabs(fTemp9);
		fRec34[0] = ((9.999999999998899e-05 * fTemp10) + (0.9999 * fRec34[1]));
		double fTemp11 = max(fRec34[0], fTemp10);
		fVec7[IOTA&32767] = fTemp11;
		fRec33[0] = ((fVec7[IOTA&32767] + fRec33[1]) - fVec7[(IOTA-iConst44)&32767]);
		fRec32[0] = ((fConst45 * fRec33[0]) + (0.999 * fRec32[1]));
		double fTemp12 = max(-1.0, min(-0.01, (fVec7[IOTA&32767] - (1.0 + (1.02 * fRec32[0])))));
		double fTemp13 = (0 - fTemp12);
		double fTemp14 = (40.1 * fTemp13);
		double fTemp15 = max(-600, fTemp14);
		double fTemp16 = (0 - fTemp15);
		double fTemp17 = (fTemp9 - fTemp12);
		double fTemp18 = (40.1 * fTemp17);
		double fTemp19 = max(-600, fTemp18);
		double fTemp20 = (0 - fTemp19);
		double fTemp21 = (((int((fabs(fTemp18) > 0.0001)))?((int((fTemp19 < -50)))?(exp(fTemp19) * fTemp20):(fTemp19 / (1 - exp(fTemp20)))):(1 + (fTemp17 * (20.05 + (134.00083333333336 * fTemp17))))) - ((int((fabs(fTemp14) > 0.0001)))?((int((fTemp15 < -50)))?(exp(fTemp15) * fTemp16):(fTemp15 / (1 - exp(fTemp16)))):(1 + (fTemp13 * (20.05 + (134.00083333333336 * fTemp13))))));
		double fTemp22 = (fConst48 * fRec36[1]);
		fRec42[0] = ((0.024937655860349125 * fTemp21) - (fConst75 * ((fConst73 * fRec42[2]) + (fConst71 * fRec42[1]))));
		double fTemp23 = (fRec42[2] + (fRec42[0] + (2 * fRec42[1])));
		fVec8[0] = fTemp23;
		fRec41[0] = ((fConst76 * ((fConst34 * fVec8[1]) + (fConst13 * fVec8[0]))) + (fConst15 * fRec41[1]));
		fRec40[0] = ((fConst77 * (fRec41[0] + fRec41[1])) + (fConst69 * fRec40[1]));
		fRec39[0] = (fRec40[0] - (fConst67 * ((fConst65 * fRec39[2]) + (fConst63 * fRec39[1]))));
		double fTemp24 = (fRec39[2] + (fRec39[0] + (2 * fRec39[1])));
		fVec9[0] = fTemp24;
		fRec38[0] = ((fConst79 * ((fConst78 * fVec9[1]) + (fConst55 * fVec9[0]))) + (fConst60 * fRec38[1]));
		fRec37[0] = (fRec38[0] - (fConst58 * ((fConst56 * fRec37[2]) + (fConst54 * fRec37[1]))));
		fRec36[0] = ((fConst58 * (((fConst53 * fRec37[0]) + (fConst80 * fRec37[1])) + (fConst53 * fRec37[2]))) - (fConst51 * ((fConst50 * fRec36[2]) + fTemp22)));
		double fTemp25 = max(-1, min(1, (fSlow7 * (fRec36[2] + (fConst51 * (fTemp22 + (fConst50 * fRec36[0])))))));
		fRec46[0] = ((fConst79 * (fVec9[0] + fVec9[1])) + (fConst60 * fRec46[1]));
		fRec45[0] = (fRec46[0] - (fConst58 * ((fConst56 * fRec45[2]) + (fConst54 * fRec45[1]))));
		double fTemp26 = (fRec45[2] + (fRec45[0] + (2 * fRec45[1])));
		fVec10[0] = fTemp26;
		fRec44[0] = ((fConst86 * ((fConst85 * fVec10[1]) + (fConst49 * fVec10[0]))) + (fConst84 * fRec44[1]));
		fRec43[0] = (fRec44[0] - (fConst82 * ((fConst81 * fRec43[2]) + (fConst48 * fRec43[1]))));
		double fTemp27 = max(-1, min(1, (fSlow8 * (((fConst47 * fRec43[0]) + (fConst87 * fRec43[1])) + (fConst47 * fRec43[2])))));
		double fTemp28 = (fConst48 * fRec47[1]);
		double fTemp29 = (fConst54 * fRec48[1]);
		fRec50[0] = ((fConst77 * ((fConst90 * fRec41[1]) + (fConst64 * fRec41[0]))) + (fConst69 * fRec50[1]));
		fRec49[0] = (fRec50[0] - (fConst67 * ((fConst65 * fRec49[2]) + (fConst63 * fRec49[1]))));
		fRec48[0] = ((fConst67 * (((fConst62 * fRec49[0]) + (fConst91 * fRec49[1])) + (fConst62 * fRec49[2]))) - (fConst89 * ((fConst88 * fRec48[2]) + fTemp29)));
		fRec47[0] = ((fRec48[2] + (fConst89 * (fTemp29 + (fConst88 * fRec48[0])))) - (fConst51 * ((fConst50 * fRec47[2]) + fTemp28)));
		double fTemp30 = max(-1, min(1, (fSlow9 * (fRec47[2] + (fConst51 * (fTemp28 + (fConst50 * fRec47[0])))))));
		fRec52[0] = ((fConst86 * (fVec10[0] + fVec10[1])) + (fConst84 * fRec52[1]));
		fRec51[0] = (fRec52[0] - (fConst82 * ((fConst81 * fRec51[2]) + (fConst48 * fRec51[1]))));
		double fTemp31 = max(-1, min(1, (fSlow10 * (fRec51[2] + (fRec51[0] + (2 * fRec51[1]))))));
		double fTemp32 = ((1.2589412 * (fTemp31 * (1 - (0.3333333333333333 * faustpower<2>(fTemp31))))) + (1.584893192 * ((fTemp30 * (1 - (0.3333333333333333 * faustpower<2>(fTemp30)))) + ((fTemp27 * (1 - (0.3333333333333333 * faustpower<2>(fTemp27)))) + (0.8413951417869425 * (fTemp25 * (1 - (0.3333333333333333 * faustpower<2>(fTemp25)))))))));
		fVec11[0] = fTemp32;
		fRec35[0] = ((fConst19 * (fVec11[0] + fVec11[1])) + (fConst18 * fRec35[1]));
		double fTemp33 = (((fSlow11 * fRec35[0]) + (fSlow6 * fTemp21)) + (fTemp8 * (1 + (fSlow4 * ((4 - (4 * fabs(fTemp8))) - 1)))));
		fVec12[0] = fTemp33;
		fRec7[0] = ((fConst19 * (fVec12[0] + fVec12[1])) + (fConst18 * fRec7[1]));
		double fTemp34 = (fRec7[0] * fRec6[0]);
		fRec4[0] = (Ftube(TUBE_TABLE_6V6_68k, ((fTemp34 + fRec5[0]) - 0.664540999999999)) - 87.91682926829267);
		fRec3[0] = ((fConst92 * ((fConst34 * fRec4[1]) + (fConst13 * fRec4[0]))) + (fConst15 * fRec3[1]));
		double fTemp35 = (1e-15 + (0.0041 * fRec54[1]));
		fVec13[0] = fTemp35;
		fRec55[0] = ((fConst19 * (fVec13[0] + fVec13[1])) + (fConst18 * fRec55[1]));
		fRec54[0] = (Ftube(TUBE_TABLE_6V6_250k, ((fRec55[0] + fTemp34) - 0.659760999999999)) - 89.08268292682925);
		fRec53[0] = ((fConst92 * ((fConst34 * fRec54[1]) + (fConst13 * fRec54[0]))) + (fConst15 * fRec53[1]));
		double fTemp36 = (min(0.7, fRec53[0]) + max(-0.75, fRec3[0]));
		fVec14[0] = fTemp36;
		fRec2[0] = (fConst94 * ((fVec14[2] + (fVec14[0] + (fConst93 * fVec14[1]))) + ((fConst12 * fRec2[2]) + (fConst10 * fRec2[1]))));
		fRec1[0] = (fConst96 * ((fRec2[2] + (fRec2[0] + (fConst95 * fRec2[1]))) + ((fConst8 * fRec1[2]) + (fConst6 * fRec1[1]))));
		fRec0[0] = (fConst98 * ((fRec1[2] + (fRec1[0] + (fConst97 * fRec1[1]))) + ((fConst4 * fRec0[2]) + (fConst2 * fRec0[1]))));
		output0[i] = (FAUSTFLOAT)fRec0[0];
		double fTemp37 = (double)input1[i];
		fVec15[0] = fTemp37;
		fRec74[0] = (fConst29 * ((fVec15[0] - fVec15[1]) + (fConst28 * fRec74[1])));
		fRec73[0] = (fConst29 * ((fRec74[0] - fRec74[1]) + (fConst28 * fRec73[1])));
		fRec72[0] = (fRec73[0] - (fConst26 * ((fConst25 * fRec72[2]) + (fConst21 * fRec72[1]))));
		fRec71[0] = ((fConst26 * (fRec72[2] + (fRec72[0] + (2 * fRec72[1])))) - (fConst24 * ((fConst23 * fRec71[2]) + (fConst21 * fRec71[1]))));
		double fTemp38 = (1e-15 + (0.027 * fRec70[1]));
		fVec16[0] = fTemp38;
		fRec75[0] = ((fConst33 * (fVec16[0] + fVec16[1])) + (fConst32 * fRec75[1]));
		fRec70[0] = (Ftube(TUBE_TABLE_6DJ8_68k, ((fRec75[0] + (fConst24 * (fRec22[0] * (fRec71[2] + (fRec71[0] + (2 * fRec71[1])))))) - 1.863945999999999)) - 60.96496296296296);
		fRec69[0] = ((fConst35 * ((fConst34 * fRec70[1]) + (fConst13 * fRec70[0]))) + (fConst15 * fRec69[1]));
		double fTemp39 = (1e-15 + (0.015 * fRec77[1]));
		fVec17[0] = fTemp39;
		fRec78[0] = ((fConst39 * (fVec17[0] + fVec17[1])) + (fConst38 * fRec78[1]));
		fRec77[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec78[0] + fRec68[1]) - 1.2716089999999989)) - 45.22606666666667);
		fRec76[0] = ((fConst35 * ((fConst34 * fRec77[1]) + (fConst13 * fRec77[0]))) + (fConst15 * fRec76[1]));
		fRec68[0] = ((0.6 * fRec76[0]) + fRec69[0]);
		fRec67[0] = ((fConst19 * (fRec68[0] + fRec68[1])) + (fConst18 * fRec67[1]));
		double fTemp40 = (1e-15 + (0.015 * fRec66[1]));
		fVec18[0] = fTemp40;
		fRec79[0] = ((fConst39 * (fVec18[0] + fVec18[1])) + (fConst38 * fRec79[1]));
		fRec66[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec79[0] + fRec67[0]) - 1.2716089999999989)) - 45.22606666666667);
		fRec65[0] = ((fConst35 * ((fConst34 * fRec66[1]) + (fConst13 * fRec66[0]))) + (fConst15 * fRec65[1]));
		double fTemp41 = (1e-15 + (0.0082 * fRec81[1]));
		fVec19[0] = fTemp41;
		fRec82[0] = ((fConst43 * (fVec19[0] + fVec19[1])) + (fConst42 * fRec82[1]));
		fRec81[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec82[0] + fRec64[1]) - 0.797042999999999)) - 32.799634146341475);
		fRec80[0] = ((fConst35 * ((fConst34 * fRec81[1]) + (fConst13 * fRec81[0]))) + (fConst15 * fRec80[1]));
		fRec64[0] = ((0.6 * fRec80[0]) + fRec65[0]);
		double fTemp42 = (1e-15 + (0.0082 * fRec63[1]));
		fVec20[0] = fTemp42;
		fRec83[0] = ((fConst43 * (fVec20[0] + fVec20[1])) + (fConst42 * fRec83[1]));
		fRec63[0] = (Ftube(TUBE_TABLE_6DJ8_250k, ((fRec83[0] + fRec64[0]) - 0.797042999999999)) - 32.799634146341475);
		fRec62[0] = ((fConst35 * ((fConst34 * fRec63[1]) + (fConst13 * fRec63[0]))) + (fConst15 * fRec62[1]));
		double fTemp43 = (fTemp1 * fRec62[0]);
		double fTemp44 = (fRec8[0] * fRec62[0]);
		double fTemp45 = fabs(fTemp44);
		fRec86[0] = ((9.999999999998899e-05 * fTemp45) + (0.9999 * fRec86[1]));
		double fTemp46 = max(fRec86[0], fTemp45);
		fVec21[IOTA&32767] = fTemp46;
		fRec85[0] = ((fVec21[IOTA&32767] + fRec85[1]) - fVec21[(IOTA-iConst44)&32767]);
		fRec84[0] = ((fConst45 * fRec85[0]) + (0.999 * fRec84[1]));
		double fTemp47 = max(-1.0, min(-0.01, (fVec21[IOTA&32767] - (1.0 + (1.02 * fRec84[0])))));
		double fTemp48 = (0 - fTemp47);
		double fTemp49 = (40.1 * fTemp48);
		double fTemp50 = max(-600, fTemp49);
		double fTemp51 = (0 - fTemp50);
		double fTemp52 = (fTemp44 - fTemp47);
		double fTemp53 = (40.1 * fTemp52);
		double fTemp54 = max(-600, fTemp53);
		double fTemp55 = (0 - fTemp54);
		double fTemp56 = (((int((fabs(fTemp53) > 0.0001)))?((int((fTemp54 < -50)))?(exp(fTemp54) * fTemp55):(fTemp54 / (1 - exp(fTemp55)))):(1 + (fTemp52 * (20.05 + (134.00083333333336 * fTemp52))))) - ((int((fabs(fTemp49) > 0.0001)))?((int((fTemp50 < -50)))?(exp(fTemp50) * fTemp51):(fTemp50 / (1 - exp(fTemp51)))):(1 + (fTemp48 * (20.05 + (134.00083333333336 * fTemp48))))));
		double fTemp57 = (fConst48 * fRec88[1]);
		fRec94[0] = ((0.024937655860349125 * fTemp56) - (fConst75 * ((fConst73 * fRec94[2]) + (fConst71 * fRec94[1]))));
		double fTemp58 = (fRec94[2] + (fRec94[0] + (2 * fRec94[1])));
		fVec22[0] = fTemp58;
		fRec93[0] = ((fConst76 * ((fConst34 * fVec22[1]) + (fConst13 * fVec22[0]))) + (fConst15 * fRec93[1]));
		fRec92[0] = ((fConst77 * (fRec93[0] + fRec93[1])) + (fConst69 * fRec92[1]));
		fRec91[0] = (fRec92[0] - (fConst67 * ((fConst65 * fRec91[2]) + (fConst63 * fRec91[1]))));
		double fTemp59 = (fRec91[2] + (fRec91[0] + (2 * fRec91[1])));
		fVec23[0] = fTemp59;
		fRec90[0] = ((fConst79 * ((fConst78 * fVec23[1]) + (fConst55 * fVec23[0]))) + (fConst60 * fRec90[1]));
		fRec89[0] = (fRec90[0] - (fConst58 * ((fConst56 * fRec89[2]) + (fConst54 * fRec89[1]))));
		fRec88[0] = ((fConst58 * (((fConst53 * fRec89[0]) + (fConst80 * fRec89[1])) + (fConst53 * fRec89[2]))) - (fConst51 * ((fConst50 * fRec88[2]) + fTemp57)));
		double fTemp60 = max(-1, min(1, (fSlow7 * (fRec88[2] + (fConst51 * (fTemp57 + (fConst50 * fRec88[0])))))));
		fRec98[0] = ((fConst79 * (fVec23[0] + fVec23[1])) + (fConst60 * fRec98[1]));
		fRec97[0] = (fRec98[0] - (fConst58 * ((fConst56 * fRec97[2]) + (fConst54 * fRec97[1]))));
		double fTemp61 = (fRec97[2] + (fRec97[0] + (2 * fRec97[1])));
		fVec24[0] = fTemp61;
		fRec96[0] = ((fConst86 * ((fConst85 * fVec24[1]) + (fConst49 * fVec24[0]))) + (fConst84 * fRec96[1]));
		fRec95[0] = (fRec96[0] - (fConst82 * ((fConst81 * fRec95[2]) + (fConst48 * fRec95[1]))));
		double fTemp62 = max(-1, min(1, (fSlow8 * (((fConst47 * fRec95[0]) + (fConst87 * fRec95[1])) + (fConst47 * fRec95[2])))));
		double fTemp63 = (fConst48 * fRec99[1]);
		double fTemp64 = (fConst54 * fRec100[1]);
		fRec102[0] = ((fConst77 * ((fConst90 * fRec93[1]) + (fConst64 * fRec93[0]))) + (fConst69 * fRec102[1]));
		fRec101[0] = (fRec102[0] - (fConst67 * ((fConst65 * fRec101[2]) + (fConst63 * fRec101[1]))));
		fRec100[0] = ((fConst67 * (((fConst62 * fRec101[0]) + (fConst91 * fRec101[1])) + (fConst62 * fRec101[2]))) - (fConst89 * ((fConst88 * fRec100[2]) + fTemp64)));
		fRec99[0] = ((fRec100[2] + (fConst89 * (fTemp64 + (fConst88 * fRec100[0])))) - (fConst51 * ((fConst50 * fRec99[2]) + fTemp63)));
		double fTemp65 = max(-1, min(1, (fSlow9 * (fRec99[2] + (fConst51 * (fTemp63 + (fConst50 * fRec99[0])))))));
		fRec104[0] = ((fConst86 * (fVec24[0] + fVec24[1])) + (fConst84 * fRec104[1]));
		fRec103[0] = (fRec104[0] - (fConst82 * ((fConst81 * fRec103[2]) + (fConst48 * fRec103[1]))));
		double fTemp66 = max(-1, min(1, (fSlow10 * (fRec103[2] + (fRec103[0] + (2 * fRec103[1]))))));
		double fTemp67 = ((1.2589412 * (fTemp66 * (1 - (0.3333333333333333 * faustpower<2>(fTemp66))))) + (1.584893192 * ((fTemp65 * (1 - (0.3333333333333333 * faustpower<2>(fTemp65)))) + ((fTemp62 * (1 - (0.3333333333333333 * faustpower<2>(fTemp62)))) + (0.8413951417869425 * (fTemp60 * (1 - (0.3333333333333333 * faustpower<2>(fTemp60)))))))));
		fVec25[0] = fTemp67;
		fRec87[0] = ((fConst19 * (fVec25[0] + fVec25[1])) + (fConst18 * fRec87[1]));
		double fTemp68 = (((fSlow11 * fRec87[0]) + (fSlow6 * fTemp56)) + (fTemp43 * (1 + (fSlow4 * ((4 - (4 * fabs(fTemp43))) - 1)))));
		fVec26[0] = fTemp68;
		fRec61[0] = ((fConst19 * (fVec26[0] + fVec26[1])) + (fConst18 * fRec61[1]));
		double fTemp69 = (fRec6[0] * fRec61[0]);
		double fTemp70 = (1e-15 + (0.0041 * fRec60[1]));
		fVec27[0] = fTemp70;
		fRec105[0] = ((fConst19 * (fVec27[0] + fVec27[1])) + (fConst18 * fRec105[1]));
		fRec60[0] = (Ftube(TUBE_TABLE_6V6_68k, ((fRec105[0] + fTemp69) - 0.664540999999999)) - 87.91682926829267);
		fRec59[0] = ((fConst92 * ((fConst34 * fRec60[1]) + (fConst13 * fRec60[0]))) + (fConst15 * fRec59[1]));
		double fTemp71 = (1e-15 + (0.0041 * fRec107[1]));
		fVec28[0] = fTemp71;
		fRec108[0] = ((fConst19 * (fVec28[0] + fVec28[1])) + (fConst18 * fRec108[1]));
		fRec107[0] = (Ftube(TUBE_TABLE_6V6_250k, ((fRec108[0] + fTemp69) - 0.659760999999999)) - 89.08268292682925);
		fRec106[0] = ((fConst92 * ((fConst34 * fRec107[1]) + (fConst13 * fRec107[0]))) + (fConst15 * fRec106[1]));
		double fTemp72 = (min(0.7, fRec106[0]) + max(-0.75, fRec59[0]));
		fVec29[0] = fTemp72;
		fRec58[0] = (fConst94 * ((fVec29[2] + (fVec29[0] + (fConst93 * fVec29[1]))) + ((fConst12 * fRec58[2]) + (fConst10 * fRec58[1]))));
		fRec57[0] = (fConst96 * ((fRec58[2] + (fRec58[0] + (fConst95 * fRec58[1]))) + ((fConst8 * fRec57[2]) + (fConst6 * fRec57[1]))));
		fRec56[0] = (fConst98 * ((fRec57[2] + (fRec57[0] + (fConst97 * fRec57[1]))) + ((fConst4 * fRec56[2]) + (fConst2 * fRec56[1]))));
		output1[i] = (FAUSTFLOAT)fRec56[0];
		// post processing
		fRec56[2] = fRec56[1]; fRec56[1] = fRec56[0];
		fRec57[2] = fRec57[1]; fRec57[1] = fRec57[0];
		fRec58[2] = fRec58[1]; fRec58[1] = fRec58[0];
		fVec29[2] = fVec29[1]; fVec29[1] = fVec29[0];
		fRec106[1] = fRec106[0];
		fRec107[1] = fRec107[0];
		fRec108[1] = fRec108[0];
		fVec28[1] = fVec28[0];
		fRec59[1] = fRec59[0];
		fRec60[1] = fRec60[0];
		fRec105[1] = fRec105[0];
		fVec27[1] = fVec27[0];
		fRec61[1] = fRec61[0];
		fVec26[1] = fVec26[0];
		fRec87[1] = fRec87[0];
		fVec25[1] = fVec25[0];
		fRec103[2] = fRec103[1]; fRec103[1] = fRec103[0];
		fRec104[1] = fRec104[0];
		fRec99[2] = fRec99[1]; fRec99[1] = fRec99[0];
		fRec100[2] = fRec100[1]; fRec100[1] = fRec100[0];
		fRec101[2] = fRec101[1]; fRec101[1] = fRec101[0];
		fRec102[1] = fRec102[0];
		fRec95[2] = fRec95[1]; fRec95[1] = fRec95[0];
		fRec96[1] = fRec96[0];
		fVec24[1] = fVec24[0];
		fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
		fRec98[1] = fRec98[0];
		fRec88[2] = fRec88[1]; fRec88[1] = fRec88[0];
		fRec89[2] = fRec89[1]; fRec89[1] = fRec89[0];
		fRec90[1] = fRec90[0];
		fVec23[1] = fVec23[0];
		fRec91[2] = fRec91[1]; fRec91[1] = fRec91[0];
		fRec92[1] = fRec92[0];
		fRec93[1] = fRec93[0];
		fVec22[1] = fVec22[0];
		fRec94[2] = fRec94[1]; fRec94[1] = fRec94[0];
		fRec84[1] = fRec84[0];
		fRec85[1] = fRec85[0];
		fRec86[1] = fRec86[0];
		fRec62[1] = fRec62[0];
		fRec63[1] = fRec63[0];
		fRec83[1] = fRec83[0];
		fVec20[1] = fVec20[0];
		fRec64[1] = fRec64[0];
		fRec80[1] = fRec80[0];
		fRec81[1] = fRec81[0];
		fRec82[1] = fRec82[0];
		fVec19[1] = fVec19[0];
		fRec65[1] = fRec65[0];
		fRec66[1] = fRec66[0];
		fRec79[1] = fRec79[0];
		fVec18[1] = fVec18[0];
		fRec67[1] = fRec67[0];
		fRec68[1] = fRec68[0];
		fRec76[1] = fRec76[0];
		fRec77[1] = fRec77[0];
		fRec78[1] = fRec78[0];
		fVec17[1] = fVec17[0];
		fRec69[1] = fRec69[0];
		fRec70[1] = fRec70[0];
		fRec75[1] = fRec75[0];
		fVec16[1] = fVec16[0];
		fRec71[2] = fRec71[1]; fRec71[1] = fRec71[0];
		fRec72[2] = fRec72[1]; fRec72[1] = fRec72[0];
		fRec73[1] = fRec73[0];
		fRec74[1] = fRec74[0];
		fVec15[1] = fVec15[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fVec14[2] = fVec14[1]; fVec14[1] = fVec14[0];
		fRec53[1] = fRec53[0];
		fRec54[1] = fRec54[0];
		fRec55[1] = fRec55[0];
		fVec13[1] = fVec13[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec7[1] = fRec7[0];
		fVec12[1] = fVec12[0];
		fRec35[1] = fRec35[0];
		fVec11[1] = fVec11[0];
		fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
		fRec52[1] = fRec52[0];
		fRec47[2] = fRec47[1]; fRec47[1] = fRec47[0];
		fRec48[2] = fRec48[1]; fRec48[1] = fRec48[0];
		fRec49[2] = fRec49[1]; fRec49[1] = fRec49[0];
		fRec50[1] = fRec50[0];
		fRec43[2] = fRec43[1]; fRec43[1] = fRec43[0];
		fRec44[1] = fRec44[0];
		fVec10[1] = fVec10[0];
		fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
		fRec46[1] = fRec46[0];
		fRec36[2] = fRec36[1]; fRec36[1] = fRec36[0];
		fRec37[2] = fRec37[1]; fRec37[1] = fRec37[0];
		fRec38[1] = fRec38[0];
		fVec9[1] = fVec9[0];
		fRec39[2] = fRec39[1]; fRec39[1] = fRec39[0];
		fRec40[1] = fRec40[0];
		fRec41[1] = fRec41[0];
		fVec8[1] = fVec8[0];
		fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
		fRec32[1] = fRec32[0];
		fRec33[1] = fRec33[0];
		IOTA = IOTA+1;
		fRec34[1] = fRec34[0];
		fRec9[1] = fRec9[0];
		fRec10[1] = fRec10[0];
		fRec31[1] = fRec31[0];
		fVec6[1] = fVec6[0];
		fRec11[1] = fRec11[0];
		fRec28[1] = fRec28[0];
		fRec29[1] = fRec29[0];
		fRec30[1] = fRec30[0];
		fVec5[1] = fVec5[0];
		fRec12[1] = fRec12[0];
		fRec13[1] = fRec13[0];
		fRec27[1] = fRec27[0];
		fVec4[1] = fVec4[0];
		fRec14[1] = fRec14[0];
		fRec15[1] = fRec15[0];
		fRec24[1] = fRec24[0];
		fRec25[1] = fRec25[0];
		fRec26[1] = fRec26[0];
		fVec3[1] = fVec3[0];
		fRec16[1] = fRec16[0];
		fRec17[1] = fRec17[0];
		fRec23[1] = fRec23[0];
		fVec2[1] = fVec2[0];
		fRec22[1] = fRec22[0];
		fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec20[1] = fRec20[0];
		fRec21[1] = fRec21[0];
		fVec1[1] = fVec1[0];
		fRec8[1] = fRec8[0];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
		fVec0[1] = fVec0[0];
	}
#undef fslider0
#undef fslider1
#undef fslider2
#undef fslider3
}

void __rt_func Dsp::compute_static(int count, float *input0, float *input1, float *output0, float *output1, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, input1, output0, output1);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DRIVE: 
		fslider3_ = (float*)data; // , 0.35, 0.0, 1.0, 0.01 
		break;
	case PREGAIN: 
		fslider2_ = (float*)data; // , -6.0, -2e+01, 2e+01, 0.1 
		break;
	case WET_DRY: 
		fslider1_ = (float*)data; // , 1e+02, 0.0, 1e+02, 1.0 
		break;
	case GAIN1: 
		fslider0_ = (float*)data; // , -6.0, -2e+01, 2e+01, 0.1 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   DRIVE, 
   PREGAIN, 
   WET_DRY, 
   GAIN1, 
} PortIndex;
*/

} // end namespace gxamp6_stereo
