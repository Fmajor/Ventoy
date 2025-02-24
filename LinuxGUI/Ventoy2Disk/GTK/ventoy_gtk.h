/******************************************************************************
 * ventoy_gtk.h
 *
 * Copyright (c) 2021, longpanda <admin@ventoy.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef __VENTOY_GTK_H__
#define __VENTOY_GTK_H__

int ventoy_disk_init(void);
void ventoy_disk_exit(void);
int ventoy_http_init(void);
void ventoy_http_exit(void);
int ventoy_log_init(void);
void ventoy_log_exit(void);
void *get_refresh_icon_raw_data(int *len);
void *get_secure_icon_raw_data(int *len);
void *get_window_icon_raw_data(int *len);
int ventoy_func_handler(const char *jsonstr, char *jsonbuf, int buflen);
const char * ventoy_code_get_cur_language(void);
int ventoy_code_get_cur_part_style(void);
void ventoy_code_set_cur_part_style(int style);
int ventoy_code_get_cur_show_all(void);
void ventoy_code_set_cur_show_all(int show_all);
void ventoy_code_set_cur_language(const char *lang);
void ventoy_code_save_cfg(void);
void on_init_window(GtkBuilder *pBuilder);
int on_exit_window(GtkWidget *widget, gpointer data) ;
void ventoy_code_refresh_device(void);
int ventoy_code_is_busy(void);
int ventoy_code_get_percent(void);
int ventoy_code_get_result(void);
int msgbox(GtkMessageType type, GtkButtonsType buttons, const char *strid);

#define MAX_PARAS   64

#define VTOY_VER_FMT "<span weight='bold' foreground='red' size='xx-large'>%s</span>"

#define LANG_LABEL_TEXT(id, str) \
    gtk_label_set_text(BUILDER_ITEM(GtkLabel, id), vtoy_json_get_string_ex(node->pstChild, str))
    
#define LANG_BUTTON_TEXT(id, str) \
    gtk_button_set_label(BUILDER_ITEM(GtkButton, id), vtoy_json_get_string_ex(node->pstChild, str))

#define LANG_MENU_ITEM_TEXT(id, str) \
    gtk_menu_item_set_label(BUILDER_ITEM(GtkMenuItem, id), vtoy_json_get_string_ex(node->pstChild, str))
    
#define LANG_CHKBTN_TEXT(id, str) \
    gtk_check_button_set_label(BUILDER_ITEM(GtkCheckButton, id), vtoy_json_get_string_ex(node->pstChild, str))

#define BUILDER_ITEM(type, id) (type *)gtk_builder_get_object(g_pXmlBuilder, id)

#define SIGNAL(id, act, func) \
    g_signal_connect(gtk_builder_get_object(g_pXmlBuilder, id), act, G_CALLBACK(func), NULL)

#define GTK_MSG_ITERATION() while (gtk_events_pending ())  gtk_main_iteration()

#endif /* __VENTOY_GTK_H__ */

