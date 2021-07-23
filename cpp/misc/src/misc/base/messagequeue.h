#ifndef MISC_BASE_MESSAGEQUEUE_H
#define MISC_BASE_MESSAGEQUEUE_H

#include <vector>
#include <mutex>

#include "misc/base/messagehandler.h"

namespace misc {

struct Message;
class MessageQueue;

/**
 * @brief MessageQueueManager does cleanup of message queues
 * 
 */
class MessageQueueManager {
 public:
  static void Add(MessageQueue *message_queue);
  static void Remove(MessageQueue *message_queue);
  static void Clear(MessageHandler *handler);

  static bool IsInitialized();

  static void ProcessAllMessageQueues();

 private:
  MessageQueueManager* Instance();

  MessageQueueManager();
  ~MessageQueueManager();

  void AddInternal(MessageQueue *message_queue);
  void RemoveInternal(MessageQueue *message_queue);
  void ClearInternal(MessageHandler *handler);

  void ProcessAllMessageQueuesInternal();

  static MessageQueueManager *instance_;
  std::vector<MessageQueue *> message_queues_;
  std::mutex mutex_;
};//class MessageQueueManager


class MessageQueue {

};//class MessageQueue

}

#endif