// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include "ISO15118_evImpl.hpp"

#include "session_logger.hpp"
#include <eviso15118/io/logging.hpp>
#include <eviso15118/session/feedback.hpp>
#include <eviso15118/session/logger.hpp>
//#include <eviso15118/tbd_controller.hpp>

namespace module {
namespace ev {

void ISO15118_evImpl::init() {
}

void ISO15118_evImpl::ready() {
}

bool ISO15118_evImpl::handle_start_charging(std::string& PaymentOption, std::string& EnergyTransferMode) {
    // your code for cmd start_charging goes here
    return true;
}

void ISO15118_evImpl::handle_stop_charging() {
    // your code for cmd stop_charging goes here
}

void ISO15118_evImpl::handle_pause_charging() {
    // your code for cmd pause_charging goes here
}

void ISO15118_evImpl::handle_set_fault() {
    // your code for cmd set_fault goes here
}

void ISO15118_evImpl::handle_set_dc_params(types::iso15118_ev::DC_EVParameters& EV_Parameters) {
    // your code for cmd set_dc_params goes here
}

void ISO15118_evImpl::handle_set_bpt_dc_params(types::iso15118_ev::DC_EV_BPT_Parameters& EV_BPT_Parameters) {
    // your code for cmd set_bpt_dc_params goes here
}

void ISO15118_evImpl::handle_enable_sae_j2847_v2g_v2h() {
    // your code for cmd enable_sae_j2847_v2g_v2h goes here
}

} // namespace ev
} // namespace module
