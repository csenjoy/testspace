#include "misc/base/messagequeue.h"

namespace misc {

//---------------------------------------------------------------
// MessageQueueManager

MessageQueueManager*MessageQueueManager::instance_ = nullptr;

void MessageQueueManager::Add(MessageQueue *message_queue) {
  return Instance()->AddInternal(message_queue);
}

void MessageQueueManager::Remove(MessageQueue *message_queue) {
  if (!instance_) return;
  return Instance()->RemoveInternal(message_queue);
}

void MessageQueueManager::Clear(MessageHandler *handler) {
  if (!instance_) return;
  return Instance()->ClearInternal(handler);
}

bool MessageQueueManager::IsInitialized() {
 return instance_ != nullptr;
}

void MessageQueueManager::ProcessAllMessageQueues() {
  if (!instance_) return;
  return Instance()->ProcessAllMessageQueuesInternal();
}

MessageQueueManager* MessageQueueManager::Instance() {
  //Note: it is not safe thread, but it is first called before all threads are
  //spawned.
  if (!instance_) {
    instance_ = new MessageQueueManager();
  }
  return instance_;
}

MessageQueueManager::MessageQueueManager() {}

MessageQueueManager::~MessageQueueManager() {}

void MessageQueueManager::AddInternal(MessageQueue *message_queue) {
  std::unique_lock<std::mutex> lock(mutex_);
  message_queues_.push_back(message_queue);
}

void MessageQueueManager::RemoveInternal(MessageQueue *message_queue) {
  bool destroy = false;
  {
    std::unique_lock<std::mutex> lock(mutex_);
    auto iter = std::find(message_queues_.begin(), message_queues_.end(), message_queue);
    if (iter != message_queues_.end()) {
      message_queues_.erase(iter);
    }
    destroy = message_queues_.empty();
  }

  if (destroy) {
    instance_ = nullptr;
    delete this;
  }
}

void MessageQueueManager::ClearInternal(MessageHandler *handler) {

}

void MessageQueueManager::ProcessAllMessageQueuesInternal() {

}




}//namespace misc