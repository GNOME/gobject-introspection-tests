/*
SPDX-License-Identifier: LGPL-2.1-or-later
SPDX-FileCopyrightText: 2018 PyGObject contributors
*/

#pragma once

#ifndef GI_TEST_DISABLE_CAIRO
#include <cairo.h>
#endif /* GI_TEST_DISABLE_CAIRO */
#include <glib-object.h>
#include <glib.h>

#include "gitestmacros.h"
#include "regress.h"

typedef struct _RegressTestBoxedCWrapper RegressTestBoxedCWrapper;

GI_TEST_EXTERN
GType regress_test_boxed_c_wrapper_get_type (void);

GI_TEST_EXTERN
RegressTestBoxedCWrapper *regress_test_boxed_c_wrapper_new (void);
GI_TEST_EXTERN
RegressTestBoxedCWrapper *regress_test_boxed_c_wrapper_copy (RegressTestBoxedCWrapper *self);
GI_TEST_EXTERN
RegressTestBoxedC *regress_test_boxed_c_wrapper_get (RegressTestBoxedCWrapper *self);

GI_TEST_EXTERN
gchar **regress_test_array_of_non_utf8_strings (void);
GI_TEST_EXTERN
void regress_test_array_fixed_boxed_none_out (RegressTestBoxedC ***objs);
GI_TEST_EXTERN
void regress_test_gvalue_out_boxed (GValue *value, int init);
GI_TEST_EXTERN
GList *regress_test_glist_boxed_none_return (guint count);
GI_TEST_EXTERN
GList *regress_test_glist_boxed_full_return (guint count);

GI_TEST_EXTERN
gboolean regress_test_array_of_fundamental_objects_in (RegressTestFundamentalObject **list, gsize len);
GI_TEST_EXTERN
RegressTestFundamentalObject **regress_test_array_of_fundamental_objects_out (gsize *len);
GI_TEST_EXTERN
gboolean regress_test_fundamental_argument_in (RegressTestFundamentalObject *obj);
GI_TEST_EXTERN
RegressTestFundamentalObject *regress_test_fundamental_argument_out (RegressTestFundamentalObject *obj);

#ifndef GI_TEST_DISABLE_CAIRO

GI_TEST_EXTERN
cairo_t *regress_test_cairo_context_none_return (void);
GI_TEST_EXTERN
void regress_test_cairo_context_full_in (cairo_t *context);
GI_TEST_EXTERN
cairo_path_t *regress_test_cairo_path_full_return (void);
GI_TEST_EXTERN
void regress_test_cairo_path_none_in (cairo_path_t *path);
GI_TEST_EXTERN
cairo_path_t *regress_test_cairo_path_full_in_full_return (cairo_path_t *path);
GI_TEST_EXTERN
void regress_test_cairo_pattern_full_in (cairo_pattern_t *pattern);
GI_TEST_EXTERN
void regress_test_cairo_pattern_none_in (cairo_pattern_t *pattern);
GI_TEST_EXTERN
cairo_pattern_t *regress_test_cairo_pattern_none_return (void);
GI_TEST_EXTERN
cairo_pattern_t *regress_test_cairo_pattern_full_return (void);
GI_TEST_EXTERN
cairo_font_options_t *regress_test_cairo_font_options_full_return (void);
GI_TEST_EXTERN
cairo_font_options_t *regress_test_cairo_font_options_none_return (void);
GI_TEST_EXTERN
void regress_test_cairo_font_options_full_in (cairo_font_options_t *options);
GI_TEST_EXTERN
void regress_test_cairo_font_options_none_in (cairo_font_options_t *options);
GI_TEST_EXTERN
cairo_font_face_t *regress_test_cairo_font_face_full_return (cairo_t *cairo);
GI_TEST_EXTERN
cairo_scaled_font_t *regress_test_cairo_scaled_font_full_return (cairo_t *cairo);
GI_TEST_EXTERN
void regress_test_cairo_region_full_in (cairo_region_t *region);
GI_TEST_EXTERN
void regress_test_cairo_surface_full_in (cairo_surface_t *surface);
GI_TEST_EXTERN
void regress_test_cairo_matrix_none_in (const cairo_matrix_t *matrix);
GI_TEST_EXTERN
cairo_matrix_t *regress_test_cairo_matrix_none_return (void);
GI_TEST_EXTERN
void regress_test_cairo_matrix_out_caller_allocates (cairo_matrix_t *matrix);

#endif

/* RegressTestAction */

typedef struct
{
  GInitiallyUnowned parent;
} RegressTestAction;

typedef struct
{
  GInitiallyUnownedClass parent_class;
} RegressTestActionClass;

GI_TEST_EXTERN
GType regress_test_action_get_type (void);

/**
 * RegressBitmask:
 *
 * A fundamental type that describes a 64-bit bitmask.
 *
 * This type resembles GStreamer's Bitmask type.
 */

/**
 * REGRESS_TYPE_BITMASK:
 *
 * a #GValue type that represents a 64-bit bitmask.
 *
 * Returns: the #GType of RegressBitmask (which is not explicitly typed)
 */

#define REGRESS_TYPE_BITMASK (regress_bitmask_get_type ())

GI_TEST_EXTERN
GType regress_bitmask_get_type (void);
