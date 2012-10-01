/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * libmm -- Access modem status & information from glib applications
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2011 - 2012 Aleksander Morgado <aleksander@gnu.org>
 * Copyright (C) 2012 Google, Inc.
 */

#ifndef _MM_MODEM_3GPP_H_
#define _MM_MODEM_3GPP_H_

#include <ModemManager.h>
#include <mm-gdbus-modem.h>

G_BEGIN_DECLS

#define MM_TYPE_MODEM_3GPP            (mm_modem_3gpp_get_type ())
#define MM_MODEM_3GPP(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MM_TYPE_MODEM_3GPP, MMModem3gpp))
#define MM_MODEM_3GPP_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), MM_TYPE_MODEM_3GPP, MMModem3gppClass))
#define MM_IS_MODEM_3GPP(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MM_TYPE_MODEM_3GPP))
#define MM_IS_MODEM_3GPP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((obj), MM_TYPE_MODEM_3GPP))
#define MM_MODEM_3GPP_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), MM_TYPE_MODEM_3GPP, MMModem3gppClass))

typedef struct _MMModem3gpp MMModem3gpp;
typedef struct _MMModem3gppClass MMModem3gppClass;

/**
 * MMModem3gpp:
 *
 * The #MMModem3gpp structure contains private data and should only be accessed
 * using the provided API.
 */
struct _MMModem3gpp {
    /*< private >*/
    MmGdbusModem3gppProxy parent;
    gpointer unused;
};

struct _MMModem3gppClass {
    /*< private >*/
    MmGdbusModem3gppProxyClass parent;
};

GType mm_modem_3gpp_get_type (void);

const gchar *mm_modem_3gpp_get_path (MMModem3gpp *self);
gchar       *mm_modem_3gpp_dup_path (MMModem3gpp *self);

const gchar *mm_modem_3gpp_get_imei          (MMModem3gpp *self);
gchar       *mm_modem_3gpp_dup_imei          (MMModem3gpp *self);

const gchar *mm_modem_3gpp_get_operator_code (MMModem3gpp *self);
gchar       *mm_modem_3gpp_dup_operator_code (MMModem3gpp *self);

const gchar *mm_modem_3gpp_get_operator_name (MMModem3gpp *self);
gchar       *mm_modem_3gpp_dup_operator_name (MMModem3gpp *self);

MMModem3gppRegistrationState  mm_modem_3gpp_get_registration_state     (MMModem3gpp *self);

MMModem3gppFacility           mm_modem_3gpp_get_enabled_facility_locks (MMModem3gpp *self);


void     mm_modem_3gpp_register        (MMModem3gpp *self,
                                        const gchar *network_id,
                                        GCancellable *cancellable,
                                        GAsyncReadyCallback callback,
                                        gpointer user_data);
gboolean mm_modem_3gpp_register_finish (MMModem3gpp *self,
                                        GAsyncResult *res,
                                        GError **error);
gboolean mm_modem_3gpp_register_sync   (MMModem3gpp *self,
                                        const gchar *network_id,
                                        GCancellable *cancellable,
                                        GError **error);

/**
 * MMModem3gppNetwork:
 *
 * The #MMModem3gppNetwork structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _MMModem3gppNetwork MMModem3gppNetwork;

MMModem3gppNetworkAvailability  mm_modem_3gpp_network_get_availability      (const MMModem3gppNetwork *network);
const gchar                    *mm_modem_3gpp_network_get_operator_long     (const MMModem3gppNetwork *network);
const gchar                    *mm_modem_3gpp_network_get_operator_short    (const MMModem3gppNetwork *network);
const gchar                    *mm_modem_3gpp_network_get_operator_code     (const MMModem3gppNetwork *network);
MMModemAccessTechnology         mm_modem_3gpp_network_get_access_technology (const MMModem3gppNetwork *network);
void                            mm_modem_3gpp_network_free                  (MMModem3gppNetwork *network);

void   mm_modem_3gpp_scan        (MMModem3gpp *self,
                                  GCancellable *cancellable,
                                  GAsyncReadyCallback callback,
                                  gpointer user_data);
GList *mm_modem_3gpp_scan_finish (MMModem3gpp *self,
                                  GAsyncResult *res,
                                  GError **error);
GList *mm_modem_3gpp_scan_sync   (MMModem3gpp *self,
                                  GCancellable *cancellable,
                                  GError **error);

G_END_DECLS

#endif /* _MM_MODEM_3GPP_H_ */
