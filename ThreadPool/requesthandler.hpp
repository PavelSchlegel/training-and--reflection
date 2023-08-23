#include "threadpool.hpp"

class RequestHandler { //трансмиттер-приемник
   public:
       RequestHandler();
       ~RequestHandler();
       // отправка запроса на выполнение
       res_type pushRequest(func_ptr f, int id, int arg);
   private:
       // пул потоков
       Thread_Pool m_tpool;
};