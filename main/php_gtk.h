/*
 * PHP-GTK - The PHP language bindings for GTK+
 *
 * Copyright (C) 2001 Andrei Zmievski <andrei@php.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
/* $Id$: */

#ifndef _PHP_GTK_H
#define _PHP_GTK_H

#include "php_gtk_module.h"
#include "gtk/gtkinvisible.h"

#if HAVE_PHP_GTK

#include <gtk/gtk.h>

extern int le_gtk;
extern int le_php_gtk_wrapper;
extern int le_gdk_window;
extern int le_gdk_bitmap;
extern int le_gdk_color;
extern int le_gdk_colormap;
extern int le_gdk_cursor;
extern int le_gdk_visual;
extern int le_gdk_font;
extern int le_gdk_gc;
extern int le_gdk_drag_context;
extern int le_gtk_accel_group;
extern int le_gtk_style;

extern zend_class_entry *gdk_event_ce;
extern zend_class_entry *gdk_window_ce;
extern zend_class_entry *gdk_pixmap_ce;
extern zend_class_entry *gdk_bitmap_ce;
extern zend_class_entry *gdk_color_ce;
extern zend_class_entry *gdk_colormap_ce;
extern zend_class_entry *gdk_atom_ce;
extern zend_class_entry *gdk_cursor_ce;
extern zend_class_entry *gdk_visual_ce;
extern zend_class_entry *gdk_font_ce;
extern zend_class_entry *gdk_gc_ce;
extern zend_class_entry *gdk_drag_context_ce;
extern zend_class_entry *gtk_selection_data_ce;
extern zend_class_entry *gtk_ctree_node_ce;
extern zend_class_entry *gtk_accel_group_ce;
extern zend_class_entry *gtk_style_ce;
extern zend_class_entry *gtk_box_child_ce;
extern zend_class_entry *gtk_fixed_child_ce;
extern zend_class_entry *gtk_clist_row_ce;

/* include generated class entries */
#include "src/php_gtk_gen_ce.h"

/* include generated register functions declarations */
#include "src/php_gtk_gen_reg_items_decl.h"

typedef void (*prop_getter_t)(zval *return_value, zval *object, zend_llist_element **element, int *result);
typedef int (*prop_setter_t)(zval *object, zend_llist_element **element, zval *value);

#undef PG_ERROR
#define PG_ERROR -2

/* Useful macros. */
#define PHP_GTK_GET_GENERIC(w, type, le) ((type)php_gtk_get_object(w, le))
#define PHP_GTK_GET(w) 			PHP_GTK_GET_GENERIC(w, GtkObject*, le_gtk)
#define PHP_GDK_EVENT_GET(w)	PHP_GTK_GET_GENERIC(w, GdkEvent*, le_php_gtk_wrapper)
#define PHP_GDK_WINDOW_GET(w)	PHP_GTK_GET_GENERIC(w, GdkWindow*, le_gdk_window)
#define PHP_GDK_PIXMAP_GET(w)	PHP_GTK_GET_GENERIC(w, GdkPixmap*, le_gdk_window)
#define PHP_GDK_BITMAP_GET(w)	PHP_GTK_GET_GENERIC(w, GdkBitmap*, le_gdk_bitmap)
#define PHP_GDK_COLOR_GET(w)	PHP_GTK_GET_GENERIC(w, GdkColor*, le_gdk_color)
#define PHP_GDK_COLORMAP_GET(w)	PHP_GTK_GET_GENERIC(w, GdkColormap*, le_gdk_colormap)
#define PHP_GDK_ATOM_GET(w)		(php_gdk_atom_get(w))
#define PHP_GDK_CURSOR_GET(w)	PHP_GTK_GET_GENERIC(w, GdkCursor*, le_gdk_cursor)
#define PHP_GDK_VISUAL_GET(w)	PHP_GTK_GET_GENERIC(w, GdkVisual*, le_gdk_visual)
#define PHP_GDK_FONT_GET(w)		PHP_GTK_GET_GENERIC(w, GdkFont*, le_gdk_font)
#define PHP_GDK_GC_GET(w)		PHP_GTK_GET_GENERIC(w, GdkGC*, le_gdk_gc)
#define PHP_GDK_DRAG_CONTEXT_GET(w) PHP_GTK_GET_GENERIC(w, GdkDragContext*, le_gdk_drag_context)
#define PHP_GTK_SELECTION_DATA_GET(w) PHP_GTK_GET_GENERIC(w, GtkSelectionData*, le_php_gtk_wrapper)
#define PHP_GTK_CTREE_NODE_GET(w) PHP_GTK_GET_GENERIC(w, GtkCTreeNode*, le_php_gtk_wrapper)
#define PHP_GTK_ACCEL_GROUP_GET(w) PHP_GTK_GET_GENERIC(w, GtkAccelGroup*, le_gtk_accel_group)
#define PHP_GTK_STYLE_GET(w) PHP_GTK_GET_GENERIC(w, GtkStyle*, le_gtk_style)

/* True globals. */
extern GHashTable *php_gtk_class_hash;
extern HashTable php_gtk_rsrc_hash;
extern HashTable php_gtk_prop_getters;
extern HashTable php_gtk_prop_setters;
extern HashTable php_gtk_type_hash;

/* Function declarations. */

void php_gtk_register_types(int module_number);
void php_gtk_set_object(zval *wrapper, void *obj, int rsrc_type);
void *php_gtk_get_object(zval *wrapper, int rsrc_type);
int php_gtk_get_enum_value(GtkType enum_type, zval *enum_val, int *result);
void php_gtk_destroy_notify(gpointer user_data);
void php_gtk_callback_marshal(GtkObject *o, gpointer data, guint nargs, GtkArg *args);
void php_gtk_handler_marshal(gpointer a, gpointer data, int nargs, GtkArg *args);
void php_gtk_input_marshal(gpointer a, gpointer data, int nargs, GtkArg *args);
void php_gtk_ret_from_value(GtkArg *ret, zval *value);
zval *php_gtk_args_as_hash(int nargs, GtkArg *args);
zval *php_gtk_arg_as_value(GtkArg *arg);
int php_gtk_get_flag_value(GtkType flag_type, zval *flag_val, int *result);
zval php_gtk_get_property(zend_property_reference *property_reference);
int php_gtk_set_property(zend_property_reference *property_reference, zval *value);
void php_gtk_call_function(INTERNAL_FUNCTION_PARAMETERS, zend_property_reference *property_reference);

static inline void php_gtk_register_prop_getter(zend_class_entry *ce, prop_getter_t getter)
{
	zend_hash_index_update(&php_gtk_prop_getters, (long)ce, (void*)&getter,
						   sizeof(prop_getter_t), NULL);
}

static inline void php_gtk_register_prop_setter(zend_class_entry *ce, prop_setter_t setter)
{
	zend_hash_index_update(&php_gtk_prop_setters, (long)ce, (void*)&setter,
						   sizeof(prop_setter_t), NULL);
}

/* Constructors and initializers. */
void php_gtk_object_init(GtkObject *obj, zval *wrapper);
zval *php_gtk_new(GtkObject *obj);
zval *php_gdk_event_new(GdkEvent *event);
zval *php_gdk_window_new(GdkWindow *window);
zval *php_gdk_pixmap_new(GdkPixmap *pixmap);
zval *php_gdk_bitmap_new(GdkBitmap *bitmap);
zval *php_gdk_color_new(GdkColor *color);
zval *php_gdk_colormap_new(GdkColormap *cmap);
zval *php_gdk_atom_new(GdkAtom atom);
zval *php_gdk_cursor_new(GdkCursor *cursor);
zval *php_gdk_visual_new(GdkVisual *visual);
zval *php_gdk_font_new(GdkFont *font);
zval *php_gdk_gc_new(GdkGC *gc);
zval *php_gdk_drag_context_new(GdkDragContext *context);
zval *php_gtk_selection_data_new(GtkSelectionData *data);
zval *php_gtk_ctree_node_new(GtkCTreeNode *node);
zval *php_gtk_accel_group_new(GtkAccelGroup *group);
zval *php_gtk_style_new(GtkStyle *style);
zval *php_gtk_box_child_new(GtkBoxChild *box_child);
zval *php_gtk_fixed_child_new(GtkFixedChild *fixed_child);
zval *php_gtk_clist_row_new(GtkCListRow *clist_row);

/* Utility functions. */
int php_gtk_parse_args(int argc, char *format, ...);
int php_gtk_parse_args_quiet(int argc, char *format, ...);
int php_gtk_parse_args_hash(zval *hash, char *format, ...);
int php_gtk_parse_args_hash_quiet(zval *hash, char *format, ...);
int php_gtk_check_class(zval *wrapper, zend_class_entry *expected_ce);
void php_gtk_invalidate(zval *wrapper);
zend_bool php_gtk_is_callable(zval *callable, zend_bool syntax_only, char **callable_name);
zval *php_gtk_array_as_hash(zval ***values, int num_values, int start, int length);
zval ***php_gtk_hash_as_array(zval *hash);
zval ***php_gtk_func_args(int argc);
zval *php_gtk_func_args_as_hash(int argc, int start, int length);
zval *php_gtk_build_value(char *format, ...);
char *php_gtk_zval_type_name(zval *arg);

#define NOT_STATIC_METHOD() \
	if (!this_ptr) { \
		php_error(E_WARNING, "%s() is not a static method", get_active_function_name()); \
		return; \
	}

PHP_FUNCTION(wrap_no_constructor);

#endif /* HAVE_PHP_GTK */

#endif	/* _PHP_GTK_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */
