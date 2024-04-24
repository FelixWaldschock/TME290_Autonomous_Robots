/*
 * Copyright (C) 2024 OpenDLV
 */

#include <cmath>
#include <cstdint>
#include <iostream>

#include "cluon-complete.hpp"
#include "opendlv-message-standard.hpp"

int32_t main(int32_t argc, char **argv)
{
  auto cmd = cluon::getCommandlineArguments(argc, argv);
  if (!cmd.contains("cid")) {
    std::cout << argv[0] << " is an OpenDLV microservice." << std::endl;
    std::cout << "Usage: " << argv[0] << " "
              << "--cid=<conference id; e.g. 111> "
              << "[--verbose] " << std::endl;
    return 0;
  }

  uint16_t const cid = std::stoi(cmd.at("cid"));
  bool const verbose = (cmd.count("verbose") != 0);

  if (verbose) {
    std::cout << "Starting microservice." << std::endl;
  }

  cluon::OD4Session od4(cid);

  auto onPedalPositionRequest{[&verbose](cluon::data::Envelope &&envelope) {
    auto const ppr =
        cluon::extractMessage<opendlv::proxy::PedalPositionRequest>(
            std::move(envelope));

    float pos = ppr.position();
    if (verbose) {
      std::cout << "Got pedal position " << pos << std::endl;
    }
  }};

  od4.dataTrigger(
      opendlv::proxy::PedalPositionRequest::ID(), onPedalPositionRequest);

  while (od4.isRunning()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  if (verbose) {
    std::cout << "Closing microservice." << std::endl;
  }

  return 0;
}
