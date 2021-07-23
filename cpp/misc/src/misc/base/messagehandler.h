#ifndef MISC_BASE_MESSAGEHANDLER_H
#define MISC_BASE_MESSAGEHANDLER_H

#include "misc/base/constructormagic.h"

namespace misc {

struct Message;

class MessageHandler {
 public:
  virtual ~MessageHandler();
  virtual void OnMessage(Message *msg) = 0;
 protected:
  MessageHandler() {}

 private:
  MISC_DISALLOW_COPY_AND_ASSIGN(MessageHandler);
};//class MessageHandler

}//namespace misc

#endif