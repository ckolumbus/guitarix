/******************************************************************************
*******************************************************************************

								gx_funktions from guitarix
	guitarix.cpp
	here are the unsortet global funktions from guitarix
*******************************************************************************
*******************************************************************************/


// global static fields
GtkWidget* fWindow, *menul, *menus, *pb, *midibox, *fbutton, *label1, *menuh;
GdkPixbuf*   ib, *ibm, *ibr;
GtkStatusIcon*  status_icon;
GtkWidget* livewa, *warn_dialog,*dsiable_warn ;

static float      checkbutton7;

float jackframe; // jack sample freq
float cpu_load;  // jack cpu_load
float checkbox7    = 1.0;
float checky       = 1.0;
float *get_frame   = NULL;
float *checkfreq   = NULL;
float *oversample  = NULL;

const char* stopit = "go";
const char* rcpath = " " ;
string jconvwav ;

// guitarix setting, location and related stuff
const char* guitarix_dir     = ".guitarix";
const char* guitarix_reset   = "resettings";
const char* jcapsetup_file   = "ja_ca_ssetrc";
const char* jcapfile_wavbase = "guitarix_session";
const char* default_setting  =
  "0.12 1 5000 130 1 5000 130 1 0.01 0.64 2 \n"
  "0 0.3 0.7 \n"
  "20 440 2 \n"
  "0.62 0.12 0 \n"
  "84 0 -1 9 0 101 4 0 0 34 0 9 1 20 64 12 1 20 0 0 \n"
  "-64.0 0.52 10 1.5 1.5 0 \n";


int offcut;
int lenghtcut;
int cm = 0;
int shownote = 2;
int view_mode = 0;
int showwave = 0;
int playmidi = 0;
int showit = 0;
int		gNumOutChans;
int frag;   // jack frame size
int NO_CONNECTION = 0;
int runjc = 0;
float fwarn_swap = 0;
int doit = 0;

FILE*              jcap_stream;
FILE*              control_stream1;
UI*                 interface;

jack_client_t*      client ;
jack_port_t *output_ports[4];
jack_port_t *input_ports[1];
#ifndef USE_RINGBUFFER
void   *midi_port_buf;
#else
jack_ringbuffer_t *jack_ringbuffer;
#endif

jack_port_t *midi_output_ports;
jack_nframes_t time_is;
jack_nframes_t  jackframes;

#define ASCII_START (48)

//---- system related defines and function proto
#define SYSTEM_OK (0)

#define NUM_OF_CHILD_PROC (3)
#define NO_PID (-1)

#define JACKCAP_IDX (0)
#define METERBG_IDX (1)
#define JCONV_IDX   (2)

pid_t child_pid[NUM_OF_CHILD_PROC] = {
  NO_PID,
  NO_PID,
  NO_PID
};

static FILE* gx_popen(const char*, const char*, const int);
static int   gx_pclose(FILE*, const int);
static void  gx_message_popup(const char*);
static bool  gx_capture_command(const int, string&);
static int   gx_system(const char*, 
		       const char*, 
		       const bool devnull = true, 
		       const bool escape  = false);

// ---- user directory
string gx_get_userdir()
{
  return string(getenv ("HOME")) + string("/") + string(guitarix_dir) + "/";
}

// ---- check version and if directory exists and create it if it not exist
bool gx_version_check(const char* Path)
{
    struct stat my_stat;
    string fullgxdir = gx_get_userdir();
    string rcfilename = 
      fullgxdir + string("guitarix-") + string(GX_VERSION) + string(".rc");

    if  (stat(Path, &my_stat) == 0) // directory exists
    {
        // check which version we're dealing with
        if  (stat(rcfilename.data(), &my_stat) != 0) 
	{
            // current version not there, let's create it and refresh the whole shebang
	    string oldfiles = fullgxdir + string("guitarix*rc");
	    (void)gx_system ("rm -f", oldfiles.data(), false);

	    oldfiles = fullgxdir + string("*.conf");
	    (void)gx_system ("rm -f", oldfiles.data(), false);

	    // setting file for current version
            ofstream f(rcfilename.data());
            string cim = string("guitarix-") + GX_VERSION;
            f << cim <<endl;
            f.close();

            string resetfile = fullgxdir + "resettings";
            ofstream fa(resetfile.data());
            fa <<  default_setting <<endl;
            fa.close();
        }
    }
    else // directory does not exist
    {
	// create .guitarix directory
        (void)gx_system("mkdir -p", fullgxdir.data(), false);

	// setting file for current version
	ofstream f(rcfilename.data());
	string cim = string("guitarix-") + GX_VERSION;
	f << cim <<endl;
	f.close();

	// --- create jack_capture setting file
	string tmpstr = fullgxdir + jcapsetup_file;

        (void)gx_system("touch", tmpstr.data(), false);
	(void)gx_system(
	   "echo 'jack_capture -c 2 --silent --disable-meter --port guitarix:out* ' >",
	   tmpstr.data(),
	   false
	);

	// --- version file 
	tmpstr = fullgxdir + string("version") + GX_VERSION;
        (void)gx_system("touch", tmpstr.data(), false);

	cim = string("echo 'guitarix-") + string(GX_VERSION) + "' >";
	(void)gx_system(cim.data(), tmpstr.data(), false);

	// --- guitarix own default settings
	tmpstr = fullgxdir + guitarix_reset;
        (void)gx_system("touch", tmpstr.data(), false);
	
	cim = "echo -e '" + string(default_setting) + "' >";
	(void)gx_system(cim.data(), tmpstr.data(), false);
    }

    return TRUE;
}

// ---- check pixmaps
int gx_pixmap_check()
{
    int ep = 1;
    struct stat my_stat;
    string pixmap_dir = string(GX_PIXMAPS_DIR) + "/";

    string gx_pix   = pixmap_dir + "guitarix.png";
    string midi_pix = pixmap_dir + "guitarix-midi.png";
    string warn_pix = pixmap_dir + "guitarix-warn.png";

    if ((stat(gx_pix.data(), &my_stat) != 0)   || 
	(stat(midi_pix.data(), &my_stat) != 0) ||	
	(stat(warn_pix.data(), &my_stat) != 0))
	
    {
      cerr << "<*** gx_pixmap_check: "
	   << " cannot find installed pixmaps! giving up ..."
	   << "***>" << endl;

      // maybe a bit too severe to give up ??
      exit(1);
    }

    GtkWidget *ibf =  gtk_image_new_from_file (gx_pix.data());
    ib = gtk_image_get_pixbuf (GTK_IMAGE(ibf));
    GtkWidget *stim = gtk_image_new_from_file (midi_pix.data());
    ibm = gtk_image_get_pixbuf (GTK_IMAGE(stim));
    GtkWidget *stir = gtk_image_new_from_file (warn_pix.data());
    ibr = gtk_image_get_pixbuf (GTK_IMAGE(stir));
    ep = 0;

    return ep;
}

// convert int to string
void gx_IntToString(int i, string & s)
{
  s = "";
 
  int abs_i = abs(i);
  do {
    // note: using base 10 since 10 digits (0123456789)
    char c = static_cast<char>(ASCII_START+abs_i%10);
    s.insert(0, &c, 1);
  } while ((abs_i /= 10) > 0);
  if (i < 0) s.insert(0, "-");
}

// use jack_capture for record the session, open a write stream for controll the stop funktion.
bool gx_capture(const char* capturas)
{
  jcap_stream = gx_popen(capturas, "w", JACKCAP_IDX);
  return (jcap_stream != NULL); 
}

bool		GTKUI::fInitialized = false;
list<UI*>	UI::fGuiList;

//----menu funktion play stop
void gx_play_function (GtkCheckMenuItem *menuitem, gpointer checkplay)
{
    checky = 1.0;
}
void gx_stop_function (GtkCheckMenuItem *menuitem, gpointer checkplay)
{
    checky = 0.0;
}


//----menu function gx_meterbridge
void gx_meterbridge (GtkCheckMenuItem *menuitem, gpointer checkplay)
{

  const char* app_name = "meterbridge";

  // is it installed ?
  int meterbridge_ok = gx_system("which", app_name);

  // if triggered by GUI
  if (gtk_check_menu_item_get_active(menuitem) == TRUE) 
  {
    if (meterbridge_ok == SYSTEM_OK) // all is cool and dandy
    { 
      (void)gx_system(
         app_name, 
	 "-n meterbridge_guitarix_in_out -t sco guitarix:in_0  guitarix:out_0",
	 true, true
      );

      usleep(1000); // let's give it 1ms

      // let's pgrep it: if 0, pgrep got a match
      meterbridge_ok = gx_system("pgrep", app_name);
    }
    
    if (meterbridge_ok != SYSTEM_OK) // no meterbridge installed or running
    {
      // reset meterbridge GUI button state to inactive
      gtk_check_menu_item_set_active(menuitem, FALSE);

      gx_message_popup(
         "  "
	 "WARNING [meterbridge]\n  "		       
         "meterbridge is either not installed or it could not be launched"
      );
    }
  }
}

//----menu function gx_show_oscilloscope
void gx_show_oscilloscope (GtkCheckMenuItem *menuitem, gpointer checkplay)
{
    if (gtk_check_menu_item_get_active(menuitem) == TRUE)
    {
        showwave = 1;
        gtk_widget_show(livewa);
    }
    else
    {
        showwave = 0;
        gtk_widget_hide(livewa);
    }
}

//----menu function gx_tuner
void gx_tuner (GtkCheckMenuItem *menuitem, gpointer checkplay)
{
    if (gtk_check_menu_item_get_active(menuitem) == TRUE)
    {
        shownote = 1;
        gtk_widget_show(pb);
    }
    else
    {
        shownote = 0;
        gtk_widget_hide(pb);
    }
}

//---- menu function gx_midi_out
void gx_midi_out (GtkCheckMenuItem *menuitem, gpointer checkplay)
{
    if (gtk_check_menu_item_get_active(menuitem) == TRUE)
    {
        playmidi = 1;
        gtk_widget_show(midibox);
    }
    else
    {
        playmidi = 0;
        gtk_widget_hide(midibox);
    }
}


//---- start or stop record when toggle_button record is pressed
void gx_run_jack_capture (GtkWidget *widget, gpointer data)
{
    // here, const applies to pointer, not pointed data ;)
    GtkToggleButton* const cap_button = (GtkToggleButton*)widget;

    // avoid running it at startup 
    // (ugly hack due to GTK+ signalling side effect)
    static bool cap_init = false;
    if (!cap_init) 
    {
      gtk_toggle_button_set_active(cap_button, FALSE);
      cap_init = true;
      return;
    }

    // is the button toggled ?
    const gboolean tggl_state = gtk_toggle_button_get_active(cap_button);

    // ---- stop recording
    if (tggl_state == FALSE) // nope
    {
      // get jack_cap pid spawned by guitarix
      const pid_t cap_pid = child_pid[JACKCAP_IDX]; 
      
      if (cap_pid != NO_PID) // running
      {
	if (kill(cap_pid, SIGINT) == -1)
	  gx_message_popup(" Sorry, could not stop (Ctrl-C) jack_capture"); 

	(void)gx_pclose(jcap_stream, JACKCAP_IDX);
	jcap_stream = NULL;
      }

      // reset pid nonetheless
      child_pid[JACKCAP_IDX] = NO_PID;

      // let's get out of here
      return;
    }


    // ---- button has been toggled, let's try to record
    int const jack_cap_ok = gx_system("which", "jack_capture");

    // increment if capturing more than once
    static int capas = 0;

    // popup message if something goes funny
    string warning("  WARNING [jack_capture]\n  ");

    if (jack_cap_ok != SYSTEM_OK) // no jack_capture in PATH! :(
    {
      warning.append(	
	"You need jack_capture <= 0.9.30 "
	"by Kjetil S. Matheussen  \n  "
	"please look here\n  "
	"http://old.notam02.no/arkiv/src/?M=D\n"
      );
    }
    else
    {
      // so far so good, start capture
      string capturas;

      if (gx_capture_command(capas, capturas))
      {
	if (!gx_capture(capturas.data()))
	  warning.append("Sorry, could not start jack_capture"); 
      }
      else 
      {
	warning.append("Could not open wav capture file");
      }
    }

    // are we running ?
    if (child_pid[JACKCAP_IDX] != NO_PID)
    {  
      capas++;
      return;
    }

    // nope :(
    gtk_toggle_button_set_active(cap_button, FALSE);
    gx_message_popup(warning.data());
}

//----menu funktion load
void gx_load_preset (GtkMenuItem *menuitem, gpointer load_preset)
{
    JCONV_SETTINGS myJCONV_SETTINGS;
    checkbutton7 = 0;

    interface->updateAllGuis();

    GtkWidget* title = gtk_bin_get_child(GTK_BIN(menuitem));
    const gchar* text = gtk_label_get_text (GTK_LABEL(title));

    string rcfilenamere = gx_get_userdir() + "guitarixprerc";
    string tmpfilename  = gx_get_userdir() + "guitarixtmprc";
    string jc_preset    = gx_get_userdir() + string("jconv_") + string(text) + ".conf ";
    string jc_file      = gx_get_userdir() + string("jconv_set.conf");
    string file_copy    = jc_preset + jc_file;
    (void)gx_system("cp -f", file_copy.data());

    int lin;
    int zeile=0;
    int l=0;

    ifstream f(rcfilenamere.data());
    if (f.good())
    {
        string buffer;
        while (!f.eof())
        {
            getline(f, buffer);
            std::string b(" ");
            std::string::size_type in = buffer.find(b);
            if (int(in) != -1) buffer.erase(in);
            l++;
        }
        zeile = l-1;
    }
    f.close();
    lin = zeile;
    myJCONV_SETTINGS.get_jconfset ();
    interface->recallpreStatebyname(rcfilenamere.data(), tmpfilename.data(), text);
    string ttle = string("guitarix ") + text;
    gtk_window_set_title (GTK_WINDOW (fWindow), (gchar*)ttle.data());
}

//---- funktion save
void gx_save_preset (const gchar* presname)
{
    string rcfilenamere = gx_get_userdir() + "guitarixprerc";
    string tmpfilename  = gx_get_userdir() + "guitarixtmprc";

    interface->savepreStatebyname(rcfilenamere.data(), tmpfilename.data(), presname);
    if (cm == 0)
    {
        GtkWidget* menuitem = gtk_menu_item_new_with_label (presname);
        g_signal_connect (GTK_OBJECT (menuitem), "activate", G_CALLBACK (gx_load_preset), NULL);
        gtk_menu_append(GTK_MENU(menul), menuitem);
        gtk_widget_show (menuitem);
    }
    string ttle = string("guitarix ") + presname;
    gtk_window_set_title (GTK_WINDOW (fWindow), (gchar*)ttle.data());

    string jc_file      = gx_get_userdir() + string("jconv_set.conf ");
    string jc_preset    = gx_get_userdir() + string("jconv_") + string(presname) + ".conf";
    string file_copy    = jc_file + jc_preset; 
    (void)gx_system("cp", file_copy.data());
}

//----menu funktion save
void gx_save_presetn2 (GtkMenuItem *menuitem, gpointer save_preset)
{
    GtkWidget* title = gtk_bin_get_child(GTK_BIN(menuitem));
    const gchar* text = gtk_label_get_text (GTK_LABEL(title));
    gx_save_preset(text);
}

// read name for presset
void gx_get_text(GtkWidget *box)
{
    const gchar* presname = gtk_entry_get_text (GTK_ENTRY(box));
    gx_save_preset(presname);
    if (cm == 0)
    {
        GtkWidget*  menuitem = gtk_menu_item_new_with_label (presname);
        g_signal_connect (GTK_OBJECT (menuitem), "activate", G_CALLBACK (gx_save_presetn2), NULL);
        gtk_menu_append(GTK_MENU(menus), menuitem);
        gtk_widget_show (menuitem);
    }
    cm = 0;
}

//----menu funktion save
void gx_save_presetn1 (GtkMenuItem *menuitem, gpointer save_preset)
{
    GtkWidget *about, *button;
    about = gtk_dialog_new();
    button  = gtk_button_new_with_label("Ok");
    GtkWidget * box = gtk_entry_new ();
    gtk_container_add (GTK_CONTAINER (GTK_DIALOG(about)->vbox), box);
    gtk_container_add (GTK_CONTAINER (GTK_DIALOG(about)->vbox), button);
    g_signal_connect_swapped (button, "clicked",  G_CALLBACK (gx_get_text), box);
    g_signal_connect_swapped (button, "clicked",  G_CALLBACK (gtk_widget_destroy), about);
    gtk_widget_show (button);
    gtk_widget_show (box);
    gtk_widget_show (about);
}

//----menu funktion about
static void gx_show_about( GtkWidget *widget, gpointer data )
{
  string about;

  about += 
    "\n This Aplication is to a large extent provided"
    "\n with the marvelous faust compiler.Yann Orlary"
    "\n <http://faust.grame.fr/>"
    "\n A large part is based on the work of Julius Orion Smith"
    "\n<http://ccrma.stanford.edu/realsimple/faust/>"
    "\n and Albert Graef\n <http://www.musikwissenschaft.uni-mainz.de/~ag/ag.html> "
    "\n\n\n guitarix ";

  about += GX_VERSION;

  about += 
    " use jack_capture >= 0.9.30for record"
    "\n by Kjetil S. Matheussen "
    "\n http://old.notam02.no/arkiv/src/?M=D"
    "\n  it will allways record to ~/guitarix_sessionX.xxx "
    "\n for impulse response it use jconv "
    "\n byFons Adriaensen "
    "\n  http://www.kokkinizita.net/linuxaudio/index.html "
    "\n\n author: Hermann Meyer <brummer-@web.de>"
    "\n home: http://guitarix.sourceforge.net/\n";

  gx_message_popup(about.c_str());
}



//--------- class wrapper--------------------------
void flr( GtkWidget *widget, gpointer data )
{
    Resample myResample;
    myResample.fileread(widget, data);
}

void fls( GtkWidget *widget, gpointer data )
{
    JCONV_SETTINGS myJCONV_SETTINGS;
    myJCONV_SETTINGS.fileselected(widget, data);
}

void rjv( GtkWidget *widget, gpointer data )
{
    JCONV_SETTINGS myJCONV_SETTINGS;
    myJCONV_SETTINGS.runjconv(widget, data);
}

void wv( GtkWidget *widget, gpointer data )
{
    GtkWaveView myGtkWaveView;
    myGtkWaveView.gtk_waveview_set_value(widget, data);
}

int gx_dont_doit()
{
    doit =1;
    return 1;
}
int gx_doit()
{
    doit = 2;
    return 2;
}

void gx_wait_warn(const char* label)
{
    warn_dialog = gtk_dialog_new();
    gtk_window_set_destroy_with_parent(GTK_WINDOW(warn_dialog), TRUE);
    GtkWidget * box = gtk_vbox_new (0, 4);
    GtkWidget * labelt = gtk_label_new ("\nWARNING\n");
    GtkWidget * labelt1 = gtk_label_new ("CHANGING THE JACK_BUFFER_SIZE ON THE FLY \nMAY CAUSE UNPREDICTABLE EFFECTS \nTO OTHER RUNNING JACK APPLICATIONS. \nDO YOU WANT TO PROCEED ?");
    GdkColor colorGreen;
    gdk_color_parse("#a6a9aa", &colorGreen);
    gtk_widget_modify_fg (labelt1, GTK_STATE_NORMAL, &colorGreen);
    GtkStyle *style1 = gtk_widget_get_style(labelt1);
    pango_font_description_set_size(style1->font_desc, 10*PANGO_SCALE);
    pango_font_description_set_weight(style1->font_desc, PANGO_WEIGHT_BOLD);
    gtk_widget_modify_font(labelt1, style1->font_desc);
    gdk_color_parse("#ffffff", &colorGreen);
    gtk_widget_modify_fg (labelt, GTK_STATE_NORMAL, &colorGreen);
    style1 = gtk_widget_get_style(labelt);
    pango_font_description_set_size(style1->font_desc, 14*PANGO_SCALE);
    pango_font_description_set_weight(style1->font_desc, PANGO_WEIGHT_BOLD);
    gtk_widget_modify_font(labelt, style1->font_desc);
    GtkWidget * box2 = gtk_hbox_new (0, 4);
    GtkWidget * button1  = gtk_dialog_add_button(GTK_DIALOG (warn_dialog),"Yes",1);
    GtkWidget * button2  = gtk_dialog_add_button(GTK_DIALOG (warn_dialog),"No",2);
    GtkWidget * box1 = gtk_hbox_new (0, 4);
    dsiable_warn = gtk_check_button_new ();
    GtkWidget * labelt2 = gtk_label_new ("Don't bother me again with such a question, I know what I am doing");

    gtk_container_add (GTK_CONTAINER(box), labelt);
    gtk_container_add (GTK_CONTAINER(box), labelt1);
    gtk_container_add (GTK_CONTAINER(box), box2);
    gtk_container_add (GTK_CONTAINER(box), box1);
    gtk_container_add (GTK_CONTAINER(box1), dsiable_warn);
    gtk_container_add (GTK_CONTAINER(box1), labelt2);
    gtk_container_add (GTK_CONTAINER(GTK_DIALOG(warn_dialog)->vbox), box);

    gtk_widget_modify_fg (labelt2, GTK_STATE_NORMAL, &colorGreen);
    GtkStyle *style = gtk_widget_get_style(labelt2);
    pango_font_description_set_size(style->font_desc, 8*PANGO_SCALE);
    pango_font_description_set_weight(style->font_desc, PANGO_WEIGHT_LIGHT);
    gtk_widget_modify_font(labelt2, style->font_desc);

    g_signal_connect (button1, "clicked",  G_CALLBACK (gx_doit), warn_dialog);
    g_signal_connect (button2, "clicked",  G_CALLBACK (gx_dont_doit), warn_dialog);
    gtk_widget_show_all(box);

    gtk_dialog_run (GTK_DIALOG (warn_dialog));
    int woff = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(dsiable_warn));
    fwarn_swap = woff;
    gtk_widget_destroy (warn_dialog);
}

/******************************************************************************
    This code is mostly contributed by 	James Warden <warjamy@yahoo.com>
******************************************************************************/

//----menu function latency
void gx_set_jack_buffer_size(GtkCheckMenuItem *menuitem, gpointer arg)
{
    // let's avoid triggering the jack server on "inactive"
    if (gtk_check_menu_item_get_active(menuitem) == false)
        return;

    // are we a proper jack client ?
    if (!client)
    {
        cerr << "<*** guitarix.cpp: gx_set_jack_buffer_size()"
        << " we are not a jack client, server may be down ***>"
        << endl;
        return;
    }

    //int fragi = jack_get_buffer_size (client);

    // if the buffer size is the same, no need to trigger it
    jack_nframes_t buf_size = (jack_nframes_t)GPOINTER_TO_INT(arg);

    if (buf_size == jack_get_buffer_size(client))
        return;
    // first time useage warning
    if (fwarn_swap == 0.0)
    {
        gtk_check_menu_item_set_inconsistent(menuitem,TRUE);
        gx_wait_warn("WARNING");
    }
    else doit =2;
    if (doit ==2)
    {
        gtk_check_menu_item_set_inconsistent(menuitem,FALSE);
        int jcio = 0;
        if (runjc == 1)
        {
            jcio = 1;
            checkbutton7 = 0;
            checkbox7 = 0.0;
            rjv( NULL, NULL );
        }
        // let's resize the buffer
        if ( jack_set_buffer_size (client, buf_size) != 0)
            gtk_check_menu_item_set_inconsistent(menuitem,TRUE);
            //jack_set_buffer_size (client, fragi);
        // let's resize the buffer
        if (jcio == 1)
        {
            jcio = 0;
            checkbutton7 = 1;
            checkbox7 = 1.0;
            rjv( NULL, NULL );
        }
        doit = 0;
    }
    else return;

}

/******************************************************************************
    Many thanks	James aka thorgal
******************************************************************************/

//--------------------------- jack_capture settings ----------------------------------------
static void gx_show_j_c_gui( GtkWidget *widget, gpointer data )
{
    (void)system ("jack_capture_gui2 -o yes -f ~/guitarix_session -n guitarix -p /.guitarix/ja_ca_ssetrc &");
}

static gint gx_delete_event( GtkWidget *widget, GdkEvent *event, gpointer data )
{
    if (system(" pidof meterbridge > /dev/null") == 0)
    {
      (void)system("kill -15 `pidof meterbridge ` 2> /dev/null");
    }

    if (child_pid[JACKCAP_IDX] != NO_PID)
    {
      (void)kill(child_pid[JACKCAP_IDX], SIGINT);
      (void)gx_pclose(jcap_stream, JACKCAP_IDX);
    }

    if (system(" pidof jconv > /dev/null") == 0)
    {
      (void)system("command kill -2 `pidof  jconv ` 2> /dev/null") ;
      (void)gx_pclose(control_stream1, JCONV_IDX);
    }
    return 0;
}

static void gx_destroy_event( GtkWidget *widget, gpointer data )
{
    (void)gx_delete_event(widget, NULL, data);
  
    shownote = 2;
    stopit = "stop";
    showwave = 0;
    playmidi = 0;
    jack_deactivate(client);
    GtkWaveView myGtkWaveView;
    myGtkWaveView.gtk_waveview_destroy (GTK_WIDGET(livewa), NULL );
    GtkRegler myGtkRegler;
    myGtkRegler.gtk_regler_destroy ( );
    if (G_IS_OBJECT(ib))
        g_object_unref( ib);
    if (G_IS_OBJECT(ibm))
        g_object_unref( ibm);
    if (G_IS_OBJECT(ibr))
        g_object_unref(ibr);

    gtk_main_quit ();
}

// reset the extended sliders to default settings
static void gx_reset_units( GtkWidget *widget, gpointer data )
{
    const char* witchres = gtk_window_get_title(GTK_WINDOW(data));
    const char*	  home;
    home = getenv ("HOME");
    if (home == 0) home = ".";
    char                filename[256];
    snprintf(filename, 256, "%s/.guitarix/resettings", home);
    if (strcmp(witchres, "distortion") == 0) interface->recalladState(filename,  4,  16, 0);
    else if (strcmp(witchres, "freeverb") == 0) interface->recalladState(filename,  20,  24, 1);
    else if (strcmp(witchres, "ImpulseResponse") == 0) interface->recalladState(filename,  28,  32, 2);
    else if (strcmp(witchres, "crybaby") == 0) interface->recalladState(filename,  16,  20, 3);
    else if (strcmp(witchres, "midi out") == 0) interface->recalladState(filename,  44,  50, 4);
    else if (strcmp(witchres, "compressor") == 0) interface->recalladState(filename,  72,  78, 5);
}

// show extendend settings slider
void gx_show_extendet_settings(GtkWidget *widget, gpointer data)
{
    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(widget)) == TRUE)
    {
        gtk_widget_show(GTK_WIDGET(data));
        gint root_x, root_y;
        gtk_window_get_position (GTK_WINDOW(data), &root_x, &root_y);
        root_y -= 120;
        gtk_window_move(GTK_WINDOW(data), root_x, root_y);
    }
    else gtk_widget_hide(GTK_WIDGET(data));
}

static void gx_hide_extendet_settings( GtkWidget *widget, gpointer data )
{
    if (showit == 0)
    {
        gtk_widget_hide(GTK_WIDGET(fWindow));
        showit = 1;
    }
    else
    {
        gtk_widget_show(GTK_WIDGET(fWindow));
        showit = 0;
    }
}

static void gx_sytray_menu( GtkWidget *widget, gpointer data )
{
    guint32 tim = gtk_get_current_event_time ();
    gtk_menu_popup (GTK_MENU(menuh),NULL,NULL,NULL,(gpointer) menuh,2,tim);
}

//---- popen revisited for guitarix
static FILE* gx_popen(const char *cmdstring, 
		      const char *type, 
		      const int proc_idx)
{
  int   i, pfd[2];
  pid_t	pid;
  FILE	*fp;

  /* only allow "r" or "w" */
  if ((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
    errno = EINVAL;		/* required by POSIX.2 */
    return(NULL);
  }

  if (pipe(pfd) < 0)
    return(NULL);	/* errno set by pipe() */

  if ((pid = fork()) < 0)
    return(NULL);	/* errno set by fork() */

  else if (pid == 0) 
  {							
    if (*type == 'r') 
    {
      close(pfd[0]);
      if (pfd[1] != STDOUT_FILENO) 
      {
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
      }
    } 
    else 
    {
      close(pfd[1]);

      if (pfd[0] != STDIN_FILENO) 
      {
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
      }
    }

    /* close all descriptors in child_pid[] */
    for (i = 0; i < NUM_OF_CHILD_PROC; i++)
      if (child_pid[i] > 0)
	close(i);

    execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
    _exit(127);
  }

  /* parent */
  if (*type == 'r') 
  {
    close(pfd[1]);

    if ((fp = fdopen(pfd[0], type)) == NULL)
      return(NULL);

  } 
  else 
  {
    close(pfd[0]);

    if ((fp = fdopen(pfd[1], type)) == NULL)
      return(NULL);
  }

  child_pid[proc_idx] = pid; /* remember child pid for this fd */
  return(fp);
}

//---- pclose revisited for guitarix
static int gx_pclose(FILE *fp, const int proc_idx)
{
  int stat;
  pid_t	pid;
  
  if ((pid = child_pid[proc_idx]) == 0)
    return(-1);	/* fp wasn't opened by gx_popen() */
  
  // reset internal process pid 
  child_pid[proc_idx] = NO_PID;

  // check control stream
  if (!fp)
    return(-1);

  // close it
  if (fclose(fp) == EOF)
    return(-1);
  
  while (waitpid(pid, &stat, 0) < 0)
    if (errno != EINTR)
      return(-1); /* error other than EINTR from waitpid() */
  
  return(stat);	/* return child's termination status */
}

//---- guitarix system function
static int gx_system(const char* name1, 
	      const char* name2, 
	      const bool  devnull,
	      const bool  escape)
{
  string str(name1);
  str.append(" ");
  str.append(name2);

  if (devnull)
    str.append(" >& /dev/null");

  if (escape)
    str.append("&");

  //  cerr << " ********* \n system command = " << str.data() << endl;

  return system(str.data());
}

//---- popup warning
static void gx_message_popup(const char* msg)
{
  // check msg validity
  if (!msg)
  {
    cerr << "<*** gx_message_popup: "
	 << "warning message does not exist"
	 << " ***>"
	 << endl;
    return;
  }

  // build popup window
  GtkWidget *about;
  GtkWidget *label;
  GtkWidget *ok_button;

  about = gtk_dialog_new();
  ok_button  = gtk_button_new_with_label("OK");
  
  label = gtk_label_new (msg);
  
  GtkStyle *style = gtk_widget_get_style(label);

  pango_font_description_set_size(style->font_desc, 10*PANGO_SCALE);
  pango_font_description_set_weight(style->font_desc, PANGO_WEIGHT_BOLD);

  gtk_widget_modify_font(label, style->font_desc);

  gtk_label_set_selectable(GTK_LABEL(label), TRUE);

  gtk_container_add (GTK_CONTAINER (GTK_DIALOG(about)->vbox), label);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG(about)->vbox), ok_button);
  
  g_signal_connect_swapped (ok_button, "clicked",  
			    G_CALLBACK (gtk_widget_destroy), about);
  gtk_widget_show (ok_button);
  gtk_widget_show (label);
  gtk_widget_show (about);
}

//---- wav file construction for jack_capture
static bool gx_capture_command(const int idx, string& capcmd)
{
  bool ret_status = false;
  string home = getenv ("HOME");

  // should never happen on unix-like systems
  if (home.empty()) 
  {  
    home += "/home/";
    home += getenv("USER");
  }

  // jack_capture setup file
  string gfilename(home);
  gfilename += "/";
  gfilename += guitarix_dir;
  gfilename += "/";
  gfilename += jcapsetup_file;
  
  // open jack_capture setup file
  ifstream f(gfilename.data());
  
  if (f.good())
  {
    // jack_capture command
    // Note: this version of the code does not add a wav file by
    // default to ja_ca_ssetrc, so we try to avoid the wav filename if one
    // by putting the / delimiter in getline
    // it is backward compatible with older ja_ca_ssetrc files

    getline(f, capcmd, '/'); 
    f.close();

    // remove trailing \n if any
    int pos = capcmd.size()-1;

    if (capcmd.c_str()[pos] == '\n')
      capcmd.resize(pos);

    ret_status = true;
  }

  // are we good ?
  if (!ret_status)
    return false;

  // we're OK
  string idx_str;
  gx_IntToString(idx, idx_str);

  capcmd += " ";
  capcmd += home;
  capcmd += "/";
  capcmd += jcapfile_wavbase;
  capcmd += idx_str;
  capcmd += ".wav";

  return true;
}

