/*********************************************************************************************************************
* DAVE APP Name : ADC_MEASUREMENT_ADV       APP Version: 4.0.14
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/* @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2016, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-10-09:
 *     - Initial version for DAVEv4.<BR>
 *
 * 2015-10-20:
 *     - Documentation updated.<BR>
 *
 * 2015-12-15:
 *     - Added support for XMC4300 devices.<BR>
 *
 * 2016-01-18:
 *     - 1.Internal consumption of request source.<BR>
 *     - 2.Support for synchronized conversion reduced from 8 master channels to 4 .<BR>
 *     - 3.Converted the SetBoundary() API from public API to private API .<BR>
 *     - 4.Updated all APIs for the Internal consumption of request source.<BR>
 *
 *
 * 2016-02-05:
 *     - Documentation updated.<BR>
 *
 * 2016-03-18:
 *     - Added consumption of the GLOBAL ICLASS -1 for Sync. Conversions.<BR>
 *     - Added consumption of the result register-0 for subtraction mode.<BR>
 *     - Removed ADC_MEASUREMENT_ADV_SetUniformConversion().<BR>
 *     - New API ADC_MEASUREMENT_ADV_SetIclass() added to configure the GLOBAL ICLASS for Slaves. <BR>
 *
 * 2016-04-26:
 *     - The synchronized conversion in a master slave configuration is currently not supported.<BR>
 *
 * 2016-06-17:
 *     - The synchronized conversion is supported.<BR>
 *     - Modified the Sync initialization sequence to configure the EVAL bits in the slave groups.<BR>
 *
 * 2016-08-18:
 *     - Minimum sample time at low frequencies changed to incorporate Errata ADC_AI.H006 and ADC_AI.H007.
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include "adc_measurement_adv.h"

/***********************************************************************************************************************
 * EXTERN DECLARATIONS
 ***********************************************************************************************************************/


/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/

/* This function would be called in the ADC_MEASUREMENT_Init() to initialize the SR lines of the
 * Result event/channel event.
 */
static void ADC_MEASUREMENT_ADV_G1_event_config(void)
{

	/* Result Event Node Mux Configuration for IF1_I (Group-0 channel-4 Result_Register-15)*/
	XMC_VADC_GROUP_SetResultInterruptNode(VADC_G0, 15U, XMC_VADC_SR_SHARED_SR1);

}



/********************************* IF1_I ADC Channel configuration structure ********************************/
static const XMC_VADC_CHANNEL_CONFIG_t  ADC_MEASUREMENT_ADV_G1_IF1_I_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .lower_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER,
  .sync_conversion            = (uint32_t) false,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 15,                           /* GxRES[15] selected */
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect         = (uint32_t) false,                     /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) true,                      /* Highest Priority: 1 selected*/
  .alias_channel              = (int8_t) XMC_VADC_CHANNEL_ALIAS_DISABLED,   /* ALIAS is Disabled*/
};


/*IF1_I Result configuration structure*/
static const XMC_VADC_RESULT_CONFIG_t ADC_MEASUREMENT_ADV_G1_IF1_I_res_config =
{
  .data_reduction_control  = (uint32_t) 0,
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode      = (uint32_t) false,
  .part_of_fifo            = (uint32_t) false , /* No FIFO */
  .event_gen_enable        = (uint32_t) true   /* Result event Enabled*/
};

/* IF1_I ADC channel Handle */
const ADC_MEASUREMENT_ADV_CHANNEL_t ADC_MEASUREMENT_ADV_G1_IF1_I_handle =
{
  .ch_num        = (uint8_t) 4,
  .group_index   = (uint8_t) 0,
  .ch_handle     = (XMC_VADC_CHANNEL_CONFIG_t*) &ADC_MEASUREMENT_ADV_G1_IF1_I_ch_config,
  .res_handle[0] = (XMC_VADC_RESULT_CONFIG_t*) &ADC_MEASUREMENT_ADV_G1_IF1_I_res_config,   
};


static const XMC_VADC_QUEUE_CONFIG_t ADC_MEASUREMENT_ADV_G1_queue_config = {
  .conv_start_mode   = (uint32_t) XMC_VADC_STARTMODE_WFS,	/* Conversion start mode WFS/CIR/CNR*/
  .req_src_priority  = (uint32_t) XMC_VADC_GROUP_RS_PRIORITY_3, /*The queue request source priority */
  .trigger_signal    = (uint32_t) XMC_VADC_REQ_TR_F,        /*If trigger needed the signal input*/
  .trigger_edge      = (uint32_t) XMC_VADC_TRIGGER_EDGE_RISING,   /*Trigger edge needed if trigger enabled*/
  .gate_signal       = (uint32_t) XMC_VADC_REQ_GT_A,            /*If gating needed the signal input*/
  .timer_mode        = (uint32_t) 0,                            /* Disabled equidistant sampling*/
  .external_trigger	 = (uint32_t) true,         /*External trigger Enabled/Disabled*/
};

static const ADC_MEASUREMENT_ADV_QUEUE_t ADC_MEASUREMENT_ADV_G1_queue_handle =
{
  .rs_intr_handle  = {
					   .node_id          = (uint32_t) 0,
					   .priority         = (uint32_t) 0,
             .sub_priority     = 0,
					   .interrupt_enable = (bool) false,
					 },
  .iclass_config_handle = {
							.sample_time_std_conv        = (uint32_t) 0,
							.conversion_mode_standard    = (uint32_t) XMC_VADC_CONVMODE_12BIT,
							.sampling_phase_emux_channel = (uint32_t) 0,
							.conversion_mode_emux        = (uint32_t) XMC_VADC_CONVMODE_12BIT
						  },
  .queue_config_handle = &ADC_MEASUREMENT_ADV_G1_queue_config,
  .gating_mode  = XMC_VADC_GATEMODE_IGNORE,
  .srv_req_node = XMC_VADC_SR_GROUP_SR0, /*Service Request line for Request source Event */
  .iclass_num = 0
};
 
static const XMC_VADC_QUEUE_ENTRY_t ADC_MEASUREMENT_ADV_G1_IF1_I_queue_entry_0 =
{
  .channel_num        = (uint8_t) 4,
  .refill_needed      = (bool) true,
  .generate_interrupt = (bool) false,
  .external_trigger   = (bool) true,
};


static const XMC_VADC_QUEUE_ENTRY_t *ADC_MEASUREMENT_ADV_G1_queue_entries[] =
{
  (XMC_VADC_QUEUE_ENTRY_t*) (void *) &ADC_MEASUREMENT_ADV_G1_IF1_I_queue_entry_0,
};



static const ADC_MEASUREMENT_ADV_CHANNEL_t *ADC_MEASUREMENT_ADV_G1_channel_array[] =
{
  (ADC_MEASUREMENT_ADV_CHANNEL_t *) (void*) &ADC_MEASUREMENT_ADV_G1_IF1_I_handle,

};

static ADC_MEASUREMENT_ADV_STATUS_t ADC_MEASUREMENT_ADV_G1_initialization_status = ADC_MEASUREMENT_ADV_STATUS_UNINITIALIZED;

const ADC_MEASUREMENT_ADV_t ADC_MEASUREMENT_ADV_G1 =
{
  .channel_array            = ADC_MEASUREMENT_ADV_G1_channel_array,
  .local_queue_entries       = ADC_MEASUREMENT_ADV_G1_queue_entries,
  .event_config               = (ADC_MEASUREMENT_ADV_G1_event_config),
  .local_queue_handle       = (ADC_MEASUREMENT_ADV_QUEUE_t *) &ADC_MEASUREMENT_ADV_G1_queue_handle,
  .init_state               = &ADC_MEASUREMENT_ADV_G1_initialization_status,
  .req_src                  = ADC_MEASUREMENT_ADV_REQUEST_SOURCE_LOCAL_QUEUE,  
  .sync_slave_g1            = (bool) true,
  .sync_slave_g2            = (bool) true,
  .sync_slave_g3            = (bool) true,
  .sync_slave_g0            = (bool) false,
  .group_index              = (uint8_t) 0, /* VADC Group-0 is acting as Master Group */
  .total_number_of_entries  = (uint8_t) 1,
  .total_number_of_channels = (uint8_t) 1,
  .start_at_initialization  = (bool) true, 
  .configure_globiclass1    = (bool) true  
};

/**********************************************************************************************************************/

/* This function would be called in the ADC_MEASUREMENT_Init() to initialize the SR lines of the
 * Result event/channel event.
 */
static void ADC_MEASUREMENT_ADV_G2_event_config(void)
{

	/* Result Event Node Mux Configuration for IF1_Q (Group-1 channel-6 Result_Register-3)*/
	XMC_VADC_GROUP_SetResultInterruptNode(VADC_G1, 3U, XMC_VADC_SR_SHARED_SR0);

}



/********************************* IF1_Q ADC Channel configuration structure ********************************/
static const XMC_VADC_CHANNEL_CONFIG_t  ADC_MEASUREMENT_ADV_G2_IF1_Q_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .lower_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER,
  .sync_conversion            = (uint32_t) true,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 3,                           /* GxRES[3] selected */
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect         = (uint32_t) false,                     /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) true,                      /* Highest Priority: 1 selected*/
  .alias_channel              = (int8_t) XMC_VADC_CHANNEL_ALIAS_DISABLED,   /* ALIAS is Disabled*/
};


/*IF1_Q Result configuration structure*/
static const XMC_VADC_RESULT_CONFIG_t ADC_MEASUREMENT_ADV_G2_IF1_Q_res_config =
{
  .data_reduction_control  = (uint32_t) 0,
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode      = (uint32_t) false,
  .part_of_fifo            = (uint32_t) false , /* No FIFO */
  .event_gen_enable        = (uint32_t) true   /* Result event Enabled*/
};

/* IF1_Q ADC channel Handle */
const ADC_MEASUREMENT_ADV_CHANNEL_t ADC_MEASUREMENT_ADV_G2_IF1_Q_handle =
{
  .ch_num        = (uint8_t) 6,
  .group_index   = (uint8_t) 1,
  .ch_handle     = (XMC_VADC_CHANNEL_CONFIG_t*) &ADC_MEASUREMENT_ADV_G2_IF1_Q_ch_config,
  .res_handle[0] = (XMC_VADC_RESULT_CONFIG_t*) &ADC_MEASUREMENT_ADV_G2_IF1_Q_res_config,   
};


static const XMC_VADC_QUEUE_CONFIG_t ADC_MEASUREMENT_ADV_G2_queue_config = {
  .conv_start_mode   = (uint32_t) XMC_VADC_STARTMODE_WFS,	/* Conversion start mode WFS/CIR/CNR*/
  .req_src_priority  = (uint32_t) XMC_VADC_GROUP_RS_PRIORITY_3, /*The queue request source priority */
  .trigger_signal    = (uint32_t) XMC_VADC_REQ_TR_F,        /*If trigger needed the signal input*/
  .trigger_edge      = (uint32_t) XMC_VADC_TRIGGER_EDGE_RISING,   /*Trigger edge needed if trigger enabled*/
  .gate_signal       = (uint32_t) XMC_VADC_REQ_GT_A,            /*If gating needed the signal input*/
  .timer_mode        = (uint32_t) 0,                            /* Disabled equidistant sampling*/
  .external_trigger	 = (uint32_t) true,         /*External trigger Enabled/Disabled*/
};

static const ADC_MEASUREMENT_ADV_QUEUE_t ADC_MEASUREMENT_ADV_G2_queue_handle =
{
  .rs_intr_handle  = {
					   .node_id          = (uint32_t) 0,
					   .priority         = (uint32_t) 0,
             .sub_priority     = 0,
					   .interrupt_enable = (bool) false,
					 },
  .iclass_config_handle = {
							.sample_time_std_conv        = (uint32_t) 0,
							.conversion_mode_standard    = (uint32_t) XMC_VADC_CONVMODE_12BIT,
							.sampling_phase_emux_channel = (uint32_t) 0,
							.conversion_mode_emux        = (uint32_t) XMC_VADC_CONVMODE_12BIT
						  },
  .queue_config_handle = &ADC_MEASUREMENT_ADV_G2_queue_config,
  .gating_mode  = XMC_VADC_GATEMODE_IGNORE,
  .srv_req_node = XMC_VADC_SR_GROUP_SR0, /*Service Request line for Request source Event */
  .iclass_num = 0
};
 
static const XMC_VADC_QUEUE_ENTRY_t ADC_MEASUREMENT_ADV_G2_IF1_Q_queue_entry_0 =
{
  .channel_num        = (uint8_t) 6,
  .refill_needed      = (bool) true,
  .generate_interrupt = (bool) false,
  .external_trigger   = (bool) true,
};


static const XMC_VADC_QUEUE_ENTRY_t *ADC_MEASUREMENT_ADV_G2_queue_entries[] =
{
  (XMC_VADC_QUEUE_ENTRY_t*) (void *) &ADC_MEASUREMENT_ADV_G2_IF1_Q_queue_entry_0,
};



static const ADC_MEASUREMENT_ADV_CHANNEL_t *ADC_MEASUREMENT_ADV_G2_channel_array[] =
{
  (ADC_MEASUREMENT_ADV_CHANNEL_t *) (void*) &ADC_MEASUREMENT_ADV_G2_IF1_Q_handle,

};

static ADC_MEASUREMENT_ADV_STATUS_t ADC_MEASUREMENT_ADV_G2_initialization_status = ADC_MEASUREMENT_ADV_STATUS_UNINITIALIZED;

const ADC_MEASUREMENT_ADV_t ADC_MEASUREMENT_ADV_G2 =
{
  .channel_array            = ADC_MEASUREMENT_ADV_G2_channel_array,
  .local_queue_entries       = ADC_MEASUREMENT_ADV_G2_queue_entries,
  .event_config               = (ADC_MEASUREMENT_ADV_G2_event_config),
  .local_queue_handle       = (ADC_MEASUREMENT_ADV_QUEUE_t *) &ADC_MEASUREMENT_ADV_G2_queue_handle,
  .init_state               = &ADC_MEASUREMENT_ADV_G2_initialization_status,
  .req_src                  = ADC_MEASUREMENT_ADV_REQUEST_SOURCE_LOCAL_QUEUE,  
  .sync_slave_g0            = (bool) false,
  .sync_slave_g1            = (bool) false,
  .sync_slave_g2            = (bool) false,
  .sync_slave_g3            = (bool) false,
  .group_index              = (uint8_t) 1, 
  .total_number_of_entries  = (uint8_t) 1,
  .total_number_of_channels = (uint8_t) 1,
  .start_at_initialization  = (bool) true, 
  .configure_globiclass1    = (bool) true  
};

/**********************************************************************************************************************/

/* This function would be called in the ADC_MEASUREMENT_Init() to initialize the SR lines of the
 * Result event/channel event.
 */
static void ADC_MEASUREMENT_ADV_G3_event_config(void)
{

	/* Result Event Node Mux Configuration for IF2_I (Group-2 channel-3 Result_Register-0)*/
	XMC_VADC_GROUP_SetResultInterruptNode(VADC_G2, 0U, XMC_VADC_SR_SHARED_SR3);

}



/********************************* IF2_I ADC Channel configuration structure ********************************/
static const XMC_VADC_CHANNEL_CONFIG_t  ADC_MEASUREMENT_ADV_G3_IF2_I_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .lower_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER,
  .sync_conversion            = (uint32_t) true,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 0,                           /* GxRES[0] selected */
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect         = (uint32_t) false,                     /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) true,                      /* Highest Priority: 1 selected*/
  .alias_channel              = (int8_t) XMC_VADC_CHANNEL_ALIAS_DISABLED,   /* ALIAS is Disabled*/
};


/*IF2_I Result configuration structure*/
static const XMC_VADC_RESULT_CONFIG_t ADC_MEASUREMENT_ADV_G3_IF2_I_res_config =
{
  .data_reduction_control  = (uint32_t) 0,
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode      = (uint32_t) false,
  .part_of_fifo            = (uint32_t) false , /* No FIFO */
  .event_gen_enable        = (uint32_t) true   /* Result event Enabled*/
};

/* IF2_I ADC channel Handle */
const ADC_MEASUREMENT_ADV_CHANNEL_t ADC_MEASUREMENT_ADV_G3_IF2_I_handle =
{
  .ch_num        = (uint8_t) 3,
  .group_index   = (uint8_t) 2,
  .ch_handle     = (XMC_VADC_CHANNEL_CONFIG_t*) &ADC_MEASUREMENT_ADV_G3_IF2_I_ch_config,
  .res_handle[0] = (XMC_VADC_RESULT_CONFIG_t*) &ADC_MEASUREMENT_ADV_G3_IF2_I_res_config,   
};


static const XMC_VADC_QUEUE_CONFIG_t ADC_MEASUREMENT_ADV_G3_queue_config = {
  .conv_start_mode   = (uint32_t) XMC_VADC_STARTMODE_WFS,	/* Conversion start mode WFS/CIR/CNR*/
  .req_src_priority  = (uint32_t) XMC_VADC_GROUP_RS_PRIORITY_3, /*The queue request source priority */
  .trigger_signal    = (uint32_t) XMC_VADC_REQ_TR_F,        /*If trigger needed the signal input*/
  .trigger_edge      = (uint32_t) XMC_VADC_TRIGGER_EDGE_RISING,   /*Trigger edge needed if trigger enabled*/
  .gate_signal       = (uint32_t) XMC_VADC_REQ_GT_A,            /*If gating needed the signal input*/
  .timer_mode        = (uint32_t) 0,                            /* Disabled equidistant sampling*/
  .external_trigger	 = (uint32_t) true,         /*External trigger Enabled/Disabled*/
};

static const ADC_MEASUREMENT_ADV_QUEUE_t ADC_MEASUREMENT_ADV_G3_queue_handle =
{
  .rs_intr_handle  = {
					   .node_id          = (uint32_t) 0,
					   .priority         = (uint32_t) 0,
             .sub_priority     = 0,
					   .interrupt_enable = (bool) false,
					 },
  .iclass_config_handle = {
							.sample_time_std_conv        = (uint32_t) 0,
							.conversion_mode_standard    = (uint32_t) XMC_VADC_CONVMODE_12BIT,
							.sampling_phase_emux_channel = (uint32_t) 0,
							.conversion_mode_emux        = (uint32_t) XMC_VADC_CONVMODE_12BIT
						  },
  .queue_config_handle = &ADC_MEASUREMENT_ADV_G3_queue_config,
  .gating_mode  = XMC_VADC_GATEMODE_IGNORE,
  .srv_req_node = XMC_VADC_SR_GROUP_SR0, /*Service Request line for Request source Event */
  .iclass_num = 0
};
 
static const XMC_VADC_QUEUE_ENTRY_t ADC_MEASUREMENT_ADV_G3_IF2_I_queue_entry_0 =
{
  .channel_num        = (uint8_t) 3,
  .refill_needed      = (bool) true,
  .generate_interrupt = (bool) false,
  .external_trigger   = (bool) true,
};


static const XMC_VADC_QUEUE_ENTRY_t *ADC_MEASUREMENT_ADV_G3_queue_entries[] =
{
  (XMC_VADC_QUEUE_ENTRY_t*) (void *) &ADC_MEASUREMENT_ADV_G3_IF2_I_queue_entry_0,
};



static const ADC_MEASUREMENT_ADV_CHANNEL_t *ADC_MEASUREMENT_ADV_G3_channel_array[] =
{
  (ADC_MEASUREMENT_ADV_CHANNEL_t *) (void*) &ADC_MEASUREMENT_ADV_G3_IF2_I_handle,

};

static ADC_MEASUREMENT_ADV_STATUS_t ADC_MEASUREMENT_ADV_G3_initialization_status = ADC_MEASUREMENT_ADV_STATUS_UNINITIALIZED;

const ADC_MEASUREMENT_ADV_t ADC_MEASUREMENT_ADV_G3 =
{
  .channel_array            = ADC_MEASUREMENT_ADV_G3_channel_array,
  .local_queue_entries       = ADC_MEASUREMENT_ADV_G3_queue_entries,
  .event_config               = (ADC_MEASUREMENT_ADV_G3_event_config),
  .local_queue_handle       = (ADC_MEASUREMENT_ADV_QUEUE_t *) &ADC_MEASUREMENT_ADV_G3_queue_handle,
  .init_state               = &ADC_MEASUREMENT_ADV_G3_initialization_status,
  .req_src                  = ADC_MEASUREMENT_ADV_REQUEST_SOURCE_LOCAL_QUEUE,  
  .sync_slave_g0            = (bool) false,
  .sync_slave_g1            = (bool) false,
  .sync_slave_g2            = (bool) false,
  .sync_slave_g3            = (bool) false,
  .group_index              = (uint8_t) 2, 
  .total_number_of_entries  = (uint8_t) 1,
  .total_number_of_channels = (uint8_t) 1,
  .start_at_initialization  = (bool) true, 
  .configure_globiclass1    = (bool) true  
};

/**********************************************************************************************************************/

/* This function would be called in the ADC_MEASUREMENT_Init() to initialize the SR lines of the
 * Result event/channel event.
 */
static void ADC_MEASUREMENT_ADV_G4_event_config(void)
{

	/* Result Event Node Mux Configuration for IF2_Q (Group-3 channel-0 Result_Register-4)*/
	XMC_VADC_GROUP_SetResultInterruptNode(VADC_G3, 4U, XMC_VADC_SR_GROUP_SR2);

}



/********************************* IF2_Q ADC Channel configuration structure ********************************/
static const XMC_VADC_CHANNEL_CONFIG_t  ADC_MEASUREMENT_ADV_G4_IF2_Q_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GROUP_CLASS1,
  .lower_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER,
  .sync_conversion            = (uint32_t) true,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 4,                           /* GxRES[4] selected */
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect         = (uint32_t) false,                     /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) true,                      /* Highest Priority: 1 selected*/
  .alias_channel              = (int8_t) XMC_VADC_CHANNEL_ALIAS_DISABLED,   /* ALIAS is Disabled*/
};


/*IF2_Q Result configuration structure*/
static const XMC_VADC_RESULT_CONFIG_t ADC_MEASUREMENT_ADV_G4_IF2_Q_res_config =
{
  .data_reduction_control  = (uint32_t) 0,
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode      = (uint32_t) false,
  .part_of_fifo            = (uint32_t) false , /* No FIFO */
  .event_gen_enable        = (uint32_t) true   /* Result event Enabled*/
};

/* IF2_Q ADC channel Handle */
const ADC_MEASUREMENT_ADV_CHANNEL_t ADC_MEASUREMENT_ADV_G4_IF2_Q_handle =
{
  .ch_num        = (uint8_t) 0,
  .group_index   = (uint8_t) 3,
  .ch_handle     = (XMC_VADC_CHANNEL_CONFIG_t*) &ADC_MEASUREMENT_ADV_G4_IF2_Q_ch_config,
  .res_handle[0] = (XMC_VADC_RESULT_CONFIG_t*) &ADC_MEASUREMENT_ADV_G4_IF2_Q_res_config,   
};


static const XMC_VADC_QUEUE_CONFIG_t ADC_MEASUREMENT_ADV_G4_queue_config = {
  .conv_start_mode   = (uint32_t) XMC_VADC_STARTMODE_WFS,	/* Conversion start mode WFS/CIR/CNR*/
  .req_src_priority  = (uint32_t) XMC_VADC_GROUP_RS_PRIORITY_3, /*The queue request source priority */
  .trigger_signal    = (uint32_t) XMC_VADC_REQ_TR_F,        /*If trigger needed the signal input*/
  .trigger_edge      = (uint32_t) XMC_VADC_TRIGGER_EDGE_RISING,   /*Trigger edge needed if trigger enabled*/
  .gate_signal       = (uint32_t) XMC_VADC_REQ_GT_A,            /*If gating needed the signal input*/
  .timer_mode        = (uint32_t) 0,                            /* Disabled equidistant sampling*/
  .external_trigger	 = (uint32_t) true,         /*External trigger Enabled/Disabled*/
};

static const ADC_MEASUREMENT_ADV_QUEUE_t ADC_MEASUREMENT_ADV_G4_queue_handle =
{
  .rs_intr_handle  = {
					   .node_id          = (uint32_t) 0,
					   .priority         = (uint32_t) 0,
             .sub_priority     = 0,
					   .interrupt_enable = (bool) false,
					 },
  .iclass_config_handle = {
							.sample_time_std_conv        = (uint32_t) 0,
							.conversion_mode_standard    = (uint32_t) XMC_VADC_CONVMODE_12BIT,
							.sampling_phase_emux_channel = (uint32_t) 0,
							.conversion_mode_emux        = (uint32_t) XMC_VADC_CONVMODE_12BIT
						  },
  .queue_config_handle = &ADC_MEASUREMENT_ADV_G4_queue_config,
  .gating_mode  = XMC_VADC_GATEMODE_IGNORE,
  .srv_req_node = XMC_VADC_SR_GROUP_SR0, /*Service Request line for Request source Event */
  .iclass_num = 1
};
 
static const XMC_VADC_QUEUE_ENTRY_t ADC_MEASUREMENT_ADV_G4_IF2_Q_queue_entry_0 =
{
  .channel_num        = (uint8_t) 0,
  .refill_needed      = (bool) true,
  .generate_interrupt = (bool) false,
  .external_trigger   = (bool) true,
};


static const XMC_VADC_QUEUE_ENTRY_t *ADC_MEASUREMENT_ADV_G4_queue_entries[] =
{
  (XMC_VADC_QUEUE_ENTRY_t*) (void *) &ADC_MEASUREMENT_ADV_G4_IF2_Q_queue_entry_0,
};



static const ADC_MEASUREMENT_ADV_CHANNEL_t *ADC_MEASUREMENT_ADV_G4_channel_array[] =
{
  (ADC_MEASUREMENT_ADV_CHANNEL_t *) (void*) &ADC_MEASUREMENT_ADV_G4_IF2_Q_handle,

};

static ADC_MEASUREMENT_ADV_STATUS_t ADC_MEASUREMENT_ADV_G4_initialization_status = ADC_MEASUREMENT_ADV_STATUS_UNINITIALIZED;

const ADC_MEASUREMENT_ADV_t ADC_MEASUREMENT_ADV_G4 =
{
  .channel_array            = ADC_MEASUREMENT_ADV_G4_channel_array,
  .local_queue_entries       = ADC_MEASUREMENT_ADV_G4_queue_entries,
  .event_config               = (ADC_MEASUREMENT_ADV_G4_event_config),
  .local_queue_handle       = (ADC_MEASUREMENT_ADV_QUEUE_t *) &ADC_MEASUREMENT_ADV_G4_queue_handle,
  .init_state               = &ADC_MEASUREMENT_ADV_G4_initialization_status,
  .req_src                  = ADC_MEASUREMENT_ADV_REQUEST_SOURCE_LOCAL_QUEUE,  
  .sync_slave_g0            = (bool) false,
  .sync_slave_g1            = (bool) false,
  .sync_slave_g2            = (bool) false,
  .sync_slave_g3            = (bool) false,
  .group_index              = (uint8_t) 3, 
  .total_number_of_entries  = (uint8_t) 1,
  .total_number_of_channels = (uint8_t) 1,
  .start_at_initialization  = (bool) true, 
  .configure_globiclass1    = (bool) true  
};

/**********************************************************************************************************************/


/********************************* BGT24_ANA ADC Channel configuration structure ********************************/
static const XMC_VADC_CHANNEL_CONFIG_t  ADC_MEASUREMENT_SCAN_BGT24_ANA_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .lower_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select      = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER,
  .sync_conversion            = (uint32_t) false,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 9,                           /* GxRES[9] selected */
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect         = (uint32_t) false,                     /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) true,                      /* Highest Priority: 1 selected*/
  .alias_channel              = (int8_t) XMC_VADC_CHANNEL_ALIAS_DISABLED,   /* ALIAS is Disabled*/
};


/*BGT24_ANA Result configuration structure*/
static const XMC_VADC_RESULT_CONFIG_t ADC_MEASUREMENT_SCAN_BGT24_ANA_res_config =
{
  .data_reduction_control  = (uint32_t) 0,
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode      = (uint32_t) false,
  .part_of_fifo            = (uint32_t) false , /* No FIFO */
  .event_gen_enable        = (uint32_t) false   /* Disable Result event */
};

/* BGT24_ANA ADC channel Handle */
const ADC_MEASUREMENT_ADV_CHANNEL_t ADC_MEASUREMENT_SCAN_BGT24_ANA_handle =
{
  .ch_num        = (uint8_t) 5,
  .group_index   = (uint8_t) 3,
  .ch_handle     = (XMC_VADC_CHANNEL_CONFIG_t*) &ADC_MEASUREMENT_SCAN_BGT24_ANA_ch_config,
  .res_handle[0] = (XMC_VADC_RESULT_CONFIG_t*) &ADC_MEASUREMENT_SCAN_BGT24_ANA_res_config,   
};


static const XMC_VADC_SCAN_CONFIG_t ADC_MEASUREMENT_SCAN_scan_config = {
  .conv_start_mode   = (uint32_t) XMC_VADC_STARTMODE_WFS,     /* Conversion start mode WFS/CIR/CNR*/
  .req_src_priority  = (uint32_t) XMC_VADC_GROUP_RS_PRIORITY_0, /*The scan request source priority */
  .trigger_signal    = (uint32_t) XMC_VADC_REQ_TR_A,      /*If trigger needed the signal input*/
  .trigger_edge      = (uint32_t) XMC_VADC_TRIGGER_EDGE_NONE,   /*Trigger edge needed if trigger enabled*/
  .gate_signal       = (uint32_t) XMC_VADC_REQ_GT_A,            /*If gating needed the signal input*/
  .timer_mode        = (uint32_t) 0,                            /* Disabled equidistant sampling*/
  .external_trigger	 = (uint32_t) false,          /*External trigger Enabled/Disabled*/
  .req_src_interrupt = (uint32_t) false,               /*Request source event Enabled/disabled*/
  .enable_auto_scan  = (uint32_t) false,  /*Autoscan enabled/disabled */
  .load_mode          = (uint32_t) XMC_VADC_SCAN_LOAD_COMBINE,   /*Response from SCAN when a Load event occours.*/
};

static const ADC_MEASUREMENT_ADV_SCAN_t ADC_MEASUREMENT_SCAN_scan_handle =
{
  .rs_intr_handle  = {
					   .node_id          = 0,
					   .priority         = 0, 
					   .sub_priority     = 0,
					   .interrupt_enable = (bool) false,
					 },
  .iclass_config_handle = {
							.sample_time_std_conv        = (uint32_t) 0,
							.conversion_mode_standard    = (uint32_t) XMC_VADC_CONVMODE_12BIT,
							.sampling_phase_emux_channel = (uint32_t) 0,
							.conversion_mode_emux        = (uint32_t) XMC_VADC_CONVMODE_12BIT
						  },
  .scan_config_handle = &ADC_MEASUREMENT_SCAN_scan_config,
  .gating_mode  = XMC_VADC_GATEMODE_IGNORE,
  .srv_req_node = XMC_VADC_SR_GROUP_SR0, /*Service Request line for Request source Event */
  .insert_mask  = 32,
  .iclass_num = 0
};
 

static const ADC_MEASUREMENT_ADV_CHANNEL_t *ADC_MEASUREMENT_SCAN_channel_array[] =
{
  (ADC_MEASUREMENT_ADV_CHANNEL_t *) (void*) &ADC_MEASUREMENT_SCAN_BGT24_ANA_handle,

};

static ADC_MEASUREMENT_ADV_STATUS_t ADC_MEASUREMENT_SCAN_initialization_status = ADC_MEASUREMENT_ADV_STATUS_UNINITIALIZED;

const ADC_MEASUREMENT_ADV_t ADC_MEASUREMENT_SCAN =
{
  .channel_array            = ADC_MEASUREMENT_SCAN_channel_array,
  
  .event_config               = NULL,
  .local_scan_handle        = (ADC_MEASUREMENT_ADV_SCAN_t *) (void *) &ADC_MEASUREMENT_SCAN_scan_handle,
  .init_state               = &ADC_MEASUREMENT_SCAN_initialization_status,
  .req_src                  = ADC_MEASUREMENT_ADV_REQUEST_SOURCE_LOCAL_SCAN,  
  .sync_slave_g0            = (bool) false,
  .sync_slave_g1            = (bool) false,
  .sync_slave_g2            = (bool) false,
  .sync_slave_g3            = (bool) false,
  .group_index              = (uint8_t) 3, 
  .total_number_of_entries  = (uint8_t) 1,
  .total_number_of_channels = (uint8_t) 1,
  .start_at_initialization  = (bool) true, 
  .configure_globiclass1    = (bool) false  
};

/**********************************************************************************************************************/
