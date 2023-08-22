#include "requesthandler.hpp"

RequestHandler::RequestHandler()
{
   m_tpool.start();
}

RequestHandler::~RequestHandler()
{
   m_tpool.stop();
}

void RequestHandler::pushRequest(func_ptr f, int id, int arg)
{
   m_tpool.push_task(f, id, arg);
}