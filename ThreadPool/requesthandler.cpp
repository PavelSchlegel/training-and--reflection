#include "requesthandler.hpp"

RequestHandler::RequestHandler()
{
   m_tpool.start();
}

RequestHandler::~RequestHandler()
{
   m_tpool.stop();
}

res_type RequestHandler::pushRequest(func_ptr f, int id, int arg)
{
   return m_tpool.push_task(f, id, arg);
}