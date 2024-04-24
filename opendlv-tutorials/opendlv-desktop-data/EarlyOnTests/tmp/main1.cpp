#include <chrono>
#include <iostream>
#include <random>

#include "cluon-complete.hpp"
#include "messages.hpp"

int32_t main(int32_t, char **) {

  std::cout << "Program startet" << std::endl;
  MyTestMessage1 receivedMsg1;
  MyTestMessage2 receivedMsg2;
  cluon::OD4Session od4(132,
    [](cluon::data::Envelope &&envelope) noexcept {
      if (envelope.dataType() == 1091) {
        receivedMsg1 = cluon::extractMessage<MyTestMessage1>(std::move(envelope));

        std::cout << receivedMsg1.myValue() << receivedMsg1.myValue() << std::endl;
      }

        if (envelope.dataType() == 1092) {
            receivedMsg2 = cluon::extractMessage<MyTestMessage2>(std::move(envelope));
    
            std::cout << receivedMsg2.myValue() << std::endl;
        }


    });

  while (od4.isRunning()) {

    uint16_t receivedValue = 1;
    //receivedMsg.myValue();

    float value = 0.99;

    MyTestMessage2 msg;
    msg.myValue(value * receivedValue);

    od4.send(msg);

std::this_thread::sleep_for(std::chrono::duration<double>(3.0));
  }
 
  return 0;
}
