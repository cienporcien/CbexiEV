// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include "ISO15118_evImpl.hpp"

#include "session_logger.hpp"
#include <eviso15118/io/logging.hpp>
#include <eviso15118/session/feedback.hpp>
#include <eviso15118/session/logger.hpp>
#include <eviso15118/tbd_controller.hpp>

eviso15118::TbdConfig tbd_config_20;
std::unique_ptr<SessionLogger> session_logger;
eviso15118::session::feedback::Callbacks callbacks_20;
std::unique_ptr<eviso15118::TbdController> controller_20;

namespace module {
namespace ev {

static std::filesystem::path get_cert_path(const std::filesystem::path& initial_path, const std::string& config_path) {
    if (config_path.empty()) {
        return initial_path;
    }

    if (*config_path.begin() == '/') {
        return config_path;
    } else {
        return initial_path / config_path;
    }
}

static eviso15118::config::TlsNegotiationStrategy convert_tls_negotiation_strategy(const std::string& strategy) {
    using Strategy = eviso15118::config::TlsNegotiationStrategy;
    if (strategy.compare("ACCEPT_CLIENT_OFFER") == 0) {
        return Strategy::ACCEPT_CLIENT_OFFER;
    } else if (strategy.compare("ENFORCE_TLS") == 0) {
        return Strategy::ENFORCE_TLS;
    } else if (strategy.compare("ENFORCE_NO_TLS") == 0) {
        return Strategy::ENFORCE_NO_TLS;
    } else {
        EVLOG_AND_THROW(Everest::EverestConfigError("Invalid choice for tls_negotiation_strategy: " + strategy));
        // better safe than sorry
    }
}

void ISO15118_evImpl::init() {
    // RDB - No logging path in the ev interface...
    // setup logging routine
    eviso15118::io::set_logging_callback([](const std::string& msg) { EVLOG_info << msg; });

    // RDB use a temp folder instead
    std::filesystem::path p = std::filesystem::temp_directory_path();
    session_logger = std::make_unique<SessionLogger>(p.string());

    //controller_20 = std::make_unique<eviso15118::TbdController>(tbd_config_20, callbacks_20);
}

void ISO15118_evImpl::ready() {
    //RDB start looping waiting for messages and commands to come in
    // while (true) {
    //     try {
    //         controller_20->loop();
    //     } catch (const std::exception& e) {
    //         EVLOG_error << "D20 EV crashed: " << e.what();
    //         //publish_dlink_error(nullptr);
    //     }
    // }
}

bool ISO15118_evImpl::handle_start_charging(std::string& PaymentOption, std::string& EnergyTransferMode) {
    // Start sending wireless SDP messages and react to the response(s)
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
