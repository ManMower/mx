/*
 * mx-widget.h: Base class for Mx actors
 *
 * Copyright 2007 OpenedHand
 * Copyright 2008, 2009 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * Boston, MA 02111-1307, USA.
 *
 */

#if !defined(MX_H_INSIDE) && !defined(MX_COMPILATION)
#error "Only <mx/mx.h> can be included directly.h"
#endif

#ifndef __MX_WIDGET_H__
#define __MX_WIDGET_H__

#include <clutter/clutter.h>
#include <mx/mx-types.h>

G_BEGIN_DECLS

#define MX_TYPE_WIDGET                 (mx_widget_get_type ())
#define MX_WIDGET(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), MX_TYPE_WIDGET, MxWidget))
#define MX_IS_WIDGET(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MX_TYPE_WIDGET))
#define MX_WIDGET_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), MX_TYPE_WIDGET, MxWidgetClass))
#define MX_IS_WIDGET_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), MX_TYPE_WIDGET))
#define MX_WIDGET_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), MX_TYPE_WIDGET, MxWidgetClass))

typedef struct _MxWidget               MxWidget;
typedef struct _MxWidgetPrivate        MxWidgetPrivate;
typedef struct _MxWidgetClass          MxWidgetClass;

/**
 * MxWidget:
 *
 * Base class for stylable actors. The contents of the #MxWidget
 * structure are private and should only be accessed through the
 * public API.
 */
struct _MxWidget
{
  /*< private >*/
  ClutterActor parent_instance;

  MxWidgetPrivate *priv;
};

/**
 * MxWidgetClass:
 *
 * Base class for stylable actors.
 */
struct _MxWidgetClass
{
  /*< private >*/
  ClutterActorClass parent_class;

  /* vfuncs */
  void (* draw_background) (MxWidget           *self,
                            ClutterActor       *background,
                            const ClutterColor *color);
};

GType mx_widget_get_type (void) G_GNUC_CONST;

void                  mx_widget_set_style_pseudo_class (MxWidget    *actor,
                                                        const gchar *pseudo_class);
G_CONST_RETURN gchar *mx_widget_get_style_pseudo_class (MxWidget    *actor);
void                  mx_widget_set_style_class_name   (MxWidget    *actor,
                                                        const gchar *style_class);
G_CONST_RETURN gchar *mx_widget_get_style_class_name   (MxWidget    *actor);

void         mx_widget_set_has_tooltip  (MxWidget    *widget,
                                         gboolean     has_tooltip);
gboolean     mx_widget_get_has_tooltip  (MxWidget    *widget);
void         mx_widget_set_tooltip_text (MxWidget    *widget,
                                         const gchar *text);
const gchar* mx_widget_get_tooltip_text (MxWidget    *widget);

void mx_widget_show_tooltip (MxWidget *widget);
void mx_widget_hide_tooltip (MxWidget *widget);

void mx_widget_ensure_style (MxWidget *widget);


/* Only to be used by sub-classes of MxWidget */
ClutterActor *mx_widget_get_background_image (MxWidget  *actor);
ClutterActor *mx_widget_get_border_image     (MxWidget  *actor);
void          mx_widget_get_padding          (MxWidget  *widget,
                                              MxPadding *padding);
void          mx_widget_draw_background      (MxWidget  *widget);
void          mx_widget_get_available_area   (MxWidget              *widget,
                                              const ClutterActorBox *allocation,
                                              ClutterActorBox       *area);

G_END_DECLS

#endif /* __MX_WIDGET_H__ */