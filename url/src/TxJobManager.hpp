#ifndef TXJOBMANAGER_HPP_
#define TXJOBMANAGER_HPP_

#include <memory>
#include <map>
#include <mutex>
#include "Buffer.hpp"
#include "UrlSockCommon.hpp"
#include "ITxJobManager.hpp"
#include "ITxJob.hpp"

namespace urlsock
{

class TxJobManager : public ITxJobManager
{
public:
    TxJobManager() = default;
    std::shared_ptr<ITxJob> getITxJobByIpPortMessageId(IpPortMessageId ipPortMessage);
    bool createITxJob(IpPortMessageId ipPortMessage, std::shared_ptr<ITxJob>& itxJob);
    bool deleteITxJob(IpPortMessageId ipPortMessage);
    bool reportAck(IpPortMessageId ipPortMessage, uint32_t offset);
    bool reportNack(IpPortMessageId ipPortMessage,  uint32_t offset, ENackReason reason);
private:
    std::map<IpPortMessageId,std::shared_ptr<ITxJob>> mTxJobMap;
    std::mutex mTxJobMapMutex;
};

} // namespace urlsock

#endif