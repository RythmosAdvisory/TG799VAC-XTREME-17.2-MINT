/*
* <:copyright-BRCM:2013:DUAL/GPL:standard
* 
*    Copyright (c) 2013 Broadcom Corporation
*    All Rights Reserved
* 
* Unless you and Broadcom execute a separate written software license
* agreement governing use of this software, this software is licensed
* to you under the terms of the GNU General Public License version 2
* (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
* with the following added to such license:
* 
*    As a special exception, the copyright holders of this software give
*    you permission to link this software with independent modules, and
*    to copy and distribute the resulting executable under terms of your
*    choice, provided that you also meet, for each linked independent
*    module, the terms and conditions of the license of that module.
*    An independent module is a module which is not derived from this
*    software.  The special exception does not apply to any modifications
*    of the software.
* 
* Not withstanding the above, under no circumstances may you combine
* this software in any way with any other Broadcom software provided
* under a license other than the GPL, without Broadcom's express prior
* written consent.
* 
* :> 
*/


#ifndef _RDPA_LLID_H_
#define _RDPA_LLID_H_

/** \defgroup epon EPON Management
 * Objects in this group control EPON-related configuration
 */

/**
 * \defgroup llid LLID Management
 * \ingroup epon
 * Objects and functions in this group are used for LLID configuration
 * - Associating L1 channels with LLID group
 * - LLID-level operations
 * @{
 */

/** Max number of LLIDs */
#define RDPA_EPON_MAX_LLID      8

/** Max number of L1 data queues per LLID, excluding the management queue */
#define RDPA_EPON_LLID_QUEUES   8

/* llid object private data */
typedef struct {
    bdmf_index index;                           /* LLID index */
    bdmf_boolean control_enable;                /* enable control channel */
    bdmf_boolean data_enable;                   /* enable control channel */
    int16_t num_channels;                       /* number of data channels */
    int16_t channels[RDPA_EPON_LLID_QUEUES+1];  /* channels assigned to LLID: [0]-control, [1-N]-data */
    bdmf_object_handle data_egress_tm;          /* egress_tm object handle */
    bdmf_object_handle control_egress_tm;       /* egress_tm object handle */
    bdmf_index ds_def_flow;                     /* llid downstream default flow configuration index*/
} llid_drv_priv_t;

/** llid def flow per port action */
typedef struct {
    bdmf_object_handle vlan_action; /**< VLAN action object */
    bdmf_boolean drop; /**< Drop action - true/false */
} rdpa_llid_port_action_t;
/** @} end of llid Doxygen group */

/** @} end of epon Doxygen group */

#endif /* _RDPA_LLID_H_ */
