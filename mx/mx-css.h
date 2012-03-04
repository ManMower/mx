/*
 * Copyright 2009 Intel Corporation.
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
 *
 * Author: Thomas Wood <thos@gnome.org>
 *
 */

#if !defined(MX_H_INSIDE) && !defined(MX_COMPILATION)
#error "Only <mx/mx.h> can be included directly.h"
#endif

#ifndef MX_CSS_H
#define MX_CSS_H

#include <glib.h>

G_BEGIN_DECLS

typedef struct _MxStyleSheetValue MxStyleSheetValue;


/**
 * MxStyleSheet:
 *
 * The padding from the internal border of the parent container.
 */
typedef struct _MxStyleSheet MxStyleSheet;

struct _MxStyleSheetValue
{
  const gchar *string;
  const gchar *source;
};

typedef struct _MxSelector MxSelector;

GType mx_selector_get_type (void) G_GNUC_CONST;

struct _MxSelector
{
  gchar *filename;
  guint  line;
};

#include <mx/mx-stylable.h>

GType mx_style_sheet_value_get_type (void) G_GNUC_CONST;


MxStyleSheet*  mx_style_sheet_new            ();
void           mx_style_sheet_destroy        ();
gboolean       mx_style_sheet_add_from_file  (MxStyleSheet *sheet,
                                              const gchar  *filename,
                                              GError       **error);
GHashTable*    mx_style_sheet_get_properties (MxStyleSheet *sheet,
                                              MxStylable   *node);
GList*         mx_style_sheet_get_selectors (MxStyleSheet  *sheet,
                                             MxStylable    *stylable);

G_END_DECLS

#endif /* MX_CSS_H */
