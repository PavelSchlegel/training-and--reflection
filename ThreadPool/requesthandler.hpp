#include "threadpool.hpp"

class RequestHandler {
   public:
       RequestHandler();
       ~RequestHandler();
       // отправка запроса на выполнение
       void pushRequest(func_ptr f, int id, int arg);
   private:
       // пул потоков
       Thread_Pool m_tpool;
};