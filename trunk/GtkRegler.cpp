
// ***** GtkRegler.cpp *****
/******************************************************************************
part of guitarix, use  reglers with Gtk
******************************************************************************/

#include"GtkRegler.h"

#define GTK_TYPE_REGLER          (gtk_regler_get_type())
#define GTK_REGLER(obj)          (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_REGLER, GtkRegler))
#define GTK_IS_REGLER(obj)       (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_REGLER))
#define GTK_REGLER_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST ((klass),  GTK_TYPE_REGLER, GtkReglerClass))
#define GTK_IS_REGLER_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GTK_TYPE_REGLER))

GtkRegler::GtkRegler()
// GtkRegler constructor
{
 
}

GtkRegler::~GtkRegler()
{
  // Nothing specific to do...
}

struct GtkReglerClass
{
    GtkRangeClass parent_class;
    GdkPixbuf *regler_image;
    GdkPixbuf *regler_image1;
    GdkPixbuf *bigregler_image;
    GdkPixbuf *bigregler_image1;
    GdkPixbuf *toggle_image;
    GdkPixbuf *toggle_image1;
    GdkPixbuf *slider_image;
    GdkPixbuf *slider_image1;
//----------- small knob
    int regler_x;
    int regler_y;
    int regler_step; 
//----------- Big knob
    int bigknob_x;
    int bigknob_y;
    int bigknob_step; 
//----------- switcher
    int toggle_x;
    int toggle_y ;
    int toggle_step; 
//----------- horizontal slider
    int slider_x;
    int slider_y;
    int slider_step; 

//---------- use this variables with outside pixmaps
/*******************************************************************************
const char *reglerpix;
const char *bigknobpix;
const char *togglepix;
const char *sliderpix;
*******************************************************************************/
};

GType gtk_regler_get_type ();

//----------search the outside pixmaps
/*******************************************************************************
static int Existspix(const char *pix) 
{
    struct stat my_stat;
    char          rcfilename[256];
    snprintf(rcfilename, 256, "%s%s", "/usr/local/share/guitarix/",pix);
    char          rcfilename1[256];
    snprintf(rcfilename1, 256, "%s%s", "/usr/share/guitarix/",pix);
    char          rcfilename2[256];
    snprintf(rcfilename2, 256, "%s%s", "./rcstyles/",pix);
    if ( stat(rcfilename, &my_stat) == 0) return 1;
    else if ( stat(rcfilename1, &my_stat) == 0) return 2;
    else if ( stat(rcfilename2, &my_stat) == 0) return 3;
    else return 4;
}
*******************************************************************************/

//----------- draw the Regler when moved
static gboolean gtk_regler_expose (GtkWidget *widget, GdkEventExpose *event)
{
    g_assert(GTK_IS_REGLER(widget));
    
    GtkRegler *regler = GTK_REGLER(widget);
    GdkWindow *window = widget->window;
    GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));
    int reglerx = widget->allocation.x, reglery = widget->allocation.y; 
//----------- small knob
if (regler->regler_type == 0) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_step / (adj->upper - adj->lower));

    if (GTK_WIDGET_HAS_FOCUS(widget)== TRUE) {
       gtk_paint_focus(widget->style, window, GTK_STATE_NORMAL, NULL, widget, NULL, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y);

        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_image1, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y, GDK_RGB_DITHER_NORMAL, 0, 0);
       }
    else {
             gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_image, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, 0, reglerx, reglery,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y, GDK_RGB_DITHER_NORMAL, 0, 0);
           }
    }
//--------- Big knob
else if (regler->regler_type == 1) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_step / (adj->upper - adj->lower));

    if (GTK_WIDGET_HAS_FOCUS(widget)== TRUE) {
 gtk_paint_focus(widget->style, window, GTK_STATE_NORMAL, NULL, widget, NULL, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y);

        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigregler_image1, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x,0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    else {
        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigregler_image, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    }
//---------- switch
 else if (regler->regler_type == 2) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_step / (adj->upper - adj->lower));

    if (GTK_WIDGET_HAS_FOCUS(widget)== TRUE) {
        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_image1, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    else {
        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_image, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    }
//--------- horizontal slider
 else if (regler->regler_type == 3) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_step / (adj->upper - adj->lower));

    if (GTK_WIDGET_HAS_FOCUS(widget)== TRUE) {
 gtk_paint_focus(widget->style, window, GTK_STATE_NORMAL, NULL, widget, NULL, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y);

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,0,0,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,0,0);

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,0,20,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, reglerstate,0);

gdk_pixbuf_saturate_and_pixelate(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,100.0,FALSE);

gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, 0, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    else {

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,0,0,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,0,0);

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,0,20,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, reglerstate,0);

gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, 0, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    }
    return TRUE;
}
//-------------- redraw when leave
static gboolean gtk_regler_leave_out (GtkWidget *widget, GdkEventCrossing *event)
{
    g_assert(GTK_IS_REGLER(widget));
    GtkRegler *regler = GTK_REGLER(widget);
    GdkWindow *window = widget->window;
    GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));
    int reglerx = widget->allocation.x, reglery = widget->allocation.y;
//----------- small knob
if (regler->regler_type == 0) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_step / (adj->upper - adj->lower));

    gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_image, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, regler->regler_type * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
//----------- Big knob
else if (regler->regler_type == 1) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_step / (adj->upper - adj->lower));

        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigregler_image, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x,0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
//----------- switch
 else if (regler->regler_type == 2) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y) / 2;
   int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_step / (adj->upper - adj->lower));

        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_image, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
//----------- horizontal slider
 else if (regler->regler_type == 3) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_step / (adj->upper - adj->lower));

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,0,0,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,0,0);

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,0,20,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, reglerstate,0);

gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, 0, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    return TRUE;
}
//----------- redraw when enter
static gboolean gtk_regler_enter_in (GtkWidget *widget, GdkEventCrossing *event)
{
    g_assert(GTK_IS_REGLER(widget));   
    GtkRegler *regler = GTK_REGLER(widget);
    GdkWindow *window = widget->window;
    GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));
    int reglerx = widget->allocation.x, reglery = widget->allocation.y;
//----------- small knob
if (regler->regler_type == 0) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_step / (adj->upper - adj->lower));

    gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_image1, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, regler->regler_type * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y, GDK_RGB_DITHER_NORMAL, 0, 0);
   }
//----------- Big knob
else if (regler->regler_type == 1) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_step / (adj->upper - adj->lower));

        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigregler_image1, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x,0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
//----------- switch
 else if (regler->regler_type == 2) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y) / 2;
  int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_step / (adj->upper - adj->lower));

        gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_image1, reglerstate * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
//----------- horizontal slider
 else if (regler->regler_type == 3) {
    reglerx += (widget->allocation.width - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x) / 2;
    reglery += (widget->allocation.height - GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y) / 2;
    int reglerstate = (int)((adj->value - adj->lower) * GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_step / (adj->upper - adj->lower));

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,0,0,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,0,0);

gdk_pixbuf_copy_area(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x,0,20,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, reglerstate,0);

gdk_pixbuf_saturate_and_pixelate(GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1,100.0,FALSE);

gdk_draw_pixbuf(GDK_DRAWABLE(widget->window), widget->style->fg_gc[0], GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_image1, 0, 0, reglerx, reglery, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x, GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y, GDK_RGB_DITHER_NORMAL, 0, 0);
    }
    return TRUE;
}
//----------- set size for GdkDrawable per type
static void gtk_regler_size_request (GtkWidget *widget, GtkRequisition *requisition)
{
    g_assert(GTK_IS_REGLER(widget));
    GtkRegler *regler = GTK_REGLER(widget);
//----------- small knob
if (regler->regler_type == 0) {
    requisition->width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x;
    requisition->height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y;
    }
//----------- Big knob
else if (regler->regler_type == 1) {
    requisition->width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x;
    requisition->height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y;
    }
//----------- switch
else if (regler->regler_type == 2) {
    requisition->width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x;
    requisition->height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y;
   }
//----------- horizontal slider
else if (regler->regler_type == 3) {
    requisition->width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x;
    requisition->height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y;
   }
}
//----------- set value
static void gtk_regler_set_value (GtkWidget *widget, int dir_down)
{
    g_assert(GTK_IS_REGLER(widget));
    GtkRegler *regler = GTK_REGLER(widget);
    GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));

    int oldstep = (int)(0.5f + (adj->value - adj->lower) / adj->step_increment);
    int step;
    int nsteps = (int)(0.5f + (adj->upper - adj->lower) / adj->step_increment); 
    if (dir_down)
        step = oldstep - 1;
    else
        step = oldstep + 1;    
    float value = adj->lower + step * double(adj->upper - adj->lower) / nsteps;
    gtk_widget_grab_focus(widget);
    gtk_range_set_value(GTK_RANGE(widget), value);
}
//----------- keyboard bindings
static gboolean gtk_regler_key_press (GtkWidget *widget, GdkEventKey *event)
{
    g_assert(GTK_IS_REGLER(widget));
    GtkRegler *regler = GTK_REGLER(widget);
    GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));
    switch(event->keyval)
    {
        case GDK_Home:
            gtk_range_set_value(GTK_RANGE(widget), adj->lower);
            return TRUE;
        case GDK_End:
            gtk_range_set_value(GTK_RANGE(widget), adj->upper);
            return TRUE; 
        case GDK_Up:
            gtk_regler_set_value(widget, 0);
            return TRUE;
        case GDK_Right:
            gtk_regler_set_value(widget, 0);
            return TRUE;
        case GDK_Down:
            gtk_regler_set_value(widget, 1);
            return TRUE;
        case GDK_Left:
            gtk_regler_set_value(widget, 1);
            return TRUE;
    }
    
    return FALSE;
}
//----------- mouse button pressed set value
static gboolean gtk_regler_button_press (GtkWidget *widget, GdkEventButton *event)
{
    g_assert(GTK_IS_REGLER(widget));
    GtkRegler *regler = GTK_REGLER(widget);
    gtk_widget_grab_focus(widget);
    gtk_widget_grab_default (widget);
    gtk_grab_add(widget);
//----------- small knob
if (regler->regler_type == 0) {
    regler->start_x = event->x;
    regler->start_y = event->y;
    regler->start_value = gtk_range_get_value(GTK_RANGE(widget));
    }
//----------- Big knob
else if (regler->regler_type == 1) {
    regler->start_x = event->x;
    regler->start_y = event->y;
    regler->start_value = gtk_range_get_value(GTK_RANGE(widget));
    }
//----------- switch
else if (regler->regler_type == 2) {
 
    regler->start_value = gtk_range_get_value(GTK_RANGE(widget));
    if ( regler->start_value == 0) gtk_range_set_value(GTK_RANGE(widget), 1);
    else gtk_range_set_value(GTK_RANGE(widget), 0);
    }
//----------- horizontal slider
else if (regler->regler_type == 3) {
    regler->start_x = event->x;
    regler->start_y = event->y;
    regler->start_value = gtk_range_get_value(GTK_RANGE(widget));
    }
    return TRUE;
}
//----------- mouse button release
static gboolean gtk_regler_button_release (GtkWidget *widget, GdkEventButton *event)
{
    g_assert(GTK_IS_REGLER(widget));
    if (GTK_WIDGET_HAS_GRAB(widget))
        gtk_grab_remove(widget);
    return FALSE;
}
//----------- set the vlue from mouse movement
static gboolean gtk_regler_pointer_motion (GtkWidget *widget, GdkEventMotion *event)
{
    g_assert(GTK_IS_REGLER(widget));
    GtkRegler *regler = GTK_REGLER(widget);
    GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));
    if (GTK_WIDGET_HAS_GRAB(widget)) {
        double mal;
	if (event->x-regler->start_x < 0) mal = 1.0;
        else mal = -1.0;
        gtk_range_set_value(GTK_RANGE(widget), regler->start_value - (event->y+(pow((event->x-regler->start_x)/2,2.0)*mal) - regler->start_y) *adj->step_increment); 
}
    return FALSE;
}
//----------- set value from mouseweel
static gboolean gtk_regler_scroll (GtkWidget *widget, GdkEventScroll *event)
{
    gtk_regler_set_value(widget, event->direction);
    return FALSE;
}

//----------- check for path when use outside pixmaps
/*******************************************************************************
static void check_pixmaps_path(GtkReglerClass *klass)
{
  int wois;
  wois = Existspix(klass->reglerpix);
if (wois ==1) klass->reglerpix = "/usr/local/share/guitarix/knobgrs.png";
else if (wois ==2) klass->reglerpix = "/usr/share/guitarix/knobgrs.png";
else if (wois ==3) klass->reglerpix = "./rcstyles/knobgrs.png";

  wois = Existspix(klass->bigknobpix);
if (wois ==1) klass->bigknobpix = "/usr/local/share/guitarix/knobgr.png";
else if (wois ==2) klass->bigknobpix = "/usr/share/guitarix/knobgr.png";
else if (wois ==3) klass->bigknobpix = "./rcstyles/knobgr.png";

  wois = Existspix(klass->togglepix); 
if (wois ==1) klass->togglepix = "/usr/local/share/guitarix/switchit.png";
else if (wois ==2) klass->togglepix = "/usr/share/guitarix/switchit.png";
else if (wois ==3) klass->togglepix = "./rcstyles/switchit.png";

  wois = Existspix(klass->sliderpix);
if (wois ==1) klass->sliderpix = "/usr/local/share/guitarix/slidersm.png";
else if (wois ==2) klass->sliderpix = "/usr/share/guitarix/slidersm.png";
else if (wois ==3) klass->sliderpix = "./rcstyles/slidersm.png";
}
*******************************************************************************/

//----------- init the GtkReglerClass
static void gtk_regler_class_init (GtkReglerClass *klass)
{
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);
    widget_class->enter_notify_event = gtk_regler_enter_in;
    widget_class->leave_notify_event = gtk_regler_leave_out;
    widget_class->expose_event = gtk_regler_expose;
    widget_class->size_request = gtk_regler_size_request;
    widget_class->button_press_event = gtk_regler_button_press;
    widget_class->button_release_event = gtk_regler_button_release;
    widget_class->motion_notify_event = gtk_regler_pointer_motion;
    widget_class->key_press_event = gtk_regler_key_press;
    widget_class->scroll_event = gtk_regler_scroll;

//---------- here are the inline pixmaps for regler
#include"GtkReglerpix.cpp"
/** set here the sizes and steps for the used regler, if other pixmaps**/
//--------- small knob size and steps
klass->regler_x = 25;
klass->regler_y = 25;
klass->regler_step = 88; 
//--------- big knob size and steps
klass->bigknob_x = 50;
klass->bigknob_y = 50;
klass->bigknob_step = 88; 
//--------- switch size and steps
klass->toggle_x = 37 ;
klass->toggle_y = 28 ;
klass->toggle_step = 1; 
//--------- horizontal slider size and steps
klass->slider_x = 120 ;
klass->slider_y = 10 ;
klass->slider_step = 100; 

//---------- for outside pixmaps 
/******************************************************************************
klass->reglerpix = "knobgrs.png";
klass->bigknobpix = "knobgr.png";
klass->togglepix = "switchit.png";
klass->sliderpix = "slidersm.png";
    check_pixmaps_path(klass);
******************************************************************************/

    GError *error = NULL;

//----------- Big knob
    klass->bigregler_image = gdk_pixbuf_new_from_xpm_data (knobgr_xpm);
   // klass->bigregler_image = gdk_pixbuf_new_from_file( klass->bigknobpix, &error);
    g_assert(klass->bigregler_image != NULL);
    klass->bigregler_image1 = gdk_pixbuf_copy( klass->bigregler_image );
    g_assert(klass->bigregler_image1 != NULL);
    gdk_pixbuf_saturate_and_pixelate(klass->bigregler_image1,klass->bigregler_image1,10.0,FALSE);
//----------- small knob
    //klass->regler_image = gdk_pixbuf_scale_simple(klass->bigregler_image,2225,25,GDK_INTERP_HYPER);
    klass->regler_image = gdk_pixbuf_new_from_xpm_data (knobgrs_xpm);
    // klass->regler_image = gdk_pixbuf_new_from_file( klass->reglerpix, &error);
    g_assert(klass->regler_image != NULL);
    klass->regler_image1 = gdk_pixbuf_copy( klass->regler_image );
    g_assert(klass->regler_image1 != NULL);
    gdk_pixbuf_saturate_and_pixelate(klass->regler_image1,klass->regler_image1,10.0,FALSE);
//----------- switch
    klass->toggle_image = gdk_pixbuf_new_from_xpm_data (switchit_xpm);
    // klass->toggle_image = gdk_pixbuf_new_from_file( klass->togglepix, &error);
    g_assert(klass->toggle_image != NULL);
    klass->toggle_image1 = gdk_pixbuf_copy( klass->toggle_image );
    g_assert(klass->toggle_image1 != NULL);
    gdk_pixbuf_saturate_and_pixelate(klass->toggle_image1,klass->toggle_image1,10.0,FALSE);
//----------- horizontal slider
    // klass->slider_image = gdk_pixbuf_new_from_file( klass->sliderpix, &error);
    klass->slider_image = gdk_pixbuf_new_from_xpm_data(slidersm_xpm);
    g_assert(klass->slider_image != NULL);
    klass->slider_image1 = gdk_pixbuf_copy( klass->slider_image );
    g_assert(klass->slider_image != NULL);

}
//----------- init the Regler type
static void gtk_regler_init (GtkRegler *regler)
{
    GtkWidget *widget = GTK_WIDGET(regler);
    GTK_WIDGET_SET_FLAGS (GTK_WIDGET(regler), GTK_CAN_FOCUS);
    GTK_WIDGET_SET_FLAGS (GTK_WIDGET(regler), GTK_CAN_DEFAULT);
if (regler->regler_type == 0) {
    widget->requisition.width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_x;
    widget->requisition.height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->regler_y;
    }
else if (regler->regler_type == 1) {
    widget->requisition.width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_x;
    widget->requisition.height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->bigknob_y;
    }
else if (regler->regler_type == 2) {
    widget->requisition.width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_x;
    widget->requisition.height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->toggle_y;
    }
else if (regler->regler_type == 3) {
    widget->requisition.width = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_x;
    widget->requisition.height = GTK_REGLER_CLASS(GTK_OBJECT_GET_CLASS(widget))->slider_y;
    }
}
//----------- redraw when value changed
static gboolean gtk_regler_value_changed(gpointer obj)
{
    GtkWidget *widget = (GtkWidget *)obj;
    gtk_widget_queue_draw(widget);
    return FALSE;
}
//----------- create small knob
 GtkWidget *GtkRegler::gtk_regler_new_with_adjustment(GtkAdjustment *_adjustment)
{
    GtkWidget *widget = GTK_WIDGET( g_object_new (GTK_TYPE_REGLER, NULL ));
    GtkRegler *regler = GTK_REGLER(widget);
    regler->regler_type = 0;
    if (widget) {
        gtk_range_set_adjustment(GTK_RANGE(widget), _adjustment);
        gtk_signal_connect(GTK_OBJECT(widget), "value-changed", G_CALLBACK(gtk_regler_value_changed), widget);
    }
    return widget;
}
//----------- create Big knob
 GtkWidget *GtkRegler::gtk_big_regler_new_with_adjustment(GtkAdjustment *_adjustment)
{
    GtkWidget *widget = GTK_WIDGET( g_object_new (GTK_TYPE_REGLER, NULL ));
    GtkRegler *regler = GTK_REGLER(widget);
    regler->regler_type = 1;
    if (widget) {
        gtk_range_set_adjustment(GTK_RANGE(widget), _adjustment);
        gtk_signal_connect(GTK_OBJECT(widget), "value-changed", G_CALLBACK(gtk_regler_value_changed), widget);
    }
    return widget;
}
//----------- create a switcher
 GtkWidget *GtkRegler::gtk_toggle_new_with_adjustment(GtkAdjustment *_adjustment)
{
    GtkWidget *widget = GTK_WIDGET( g_object_new (GTK_TYPE_REGLER, NULL ));
    GtkRegler *regler = GTK_REGLER(widget);
    regler->regler_type = 2;
    if (widget) {
        gtk_range_set_adjustment(GTK_RANGE(widget), _adjustment);
        gtk_signal_connect(GTK_OBJECT(widget), "value-changed", G_CALLBACK(gtk_regler_value_changed), widget);
    }
    return widget;
}
//----------- create a horizontal slider
 GtkWidget *GtkRegler::gtk_hslider_new_with_adjustment(GtkAdjustment *_adjustment)
{
    GtkWidget *widget = GTK_WIDGET( g_object_new (GTK_TYPE_REGLER, NULL ));
    GtkRegler *regler = GTK_REGLER(widget);
    regler->regler_type = 3;
    if (widget) {
        gtk_range_set_adjustment(GTK_RANGE(widget), _adjustment);
        gtk_signal_connect(GTK_OBJECT(widget), "value-changed", G_CALLBACK(gtk_regler_value_changed), widget);
    }
    return widget;
}
//----------- get the Regler type
GType gtk_regler_get_type (void)
{
    static GType kn_type = 0;
    if (!kn_type) {
        
        static const GTypeInfo kn_info = {
            sizeof(GtkReglerClass), NULL,  NULL, (GClassInitFunc)gtk_regler_class_init, NULL, NULL, sizeof (GtkRegler), 0, (GInstanceInitFunc)gtk_regler_init
        };
            kn_type = g_type_register_static(GTK_TYPE_RANGE,  "GtkRegler", &kn_info, (GTypeFlags)0);
    }
    return kn_type;
}

