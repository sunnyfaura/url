#ifndef ITXJOBMANAGERMOCK_HPP_
#define ITXJOBMANAGERMOCK_HPP_

#include <src/ITxJobManager.hpp>

namespace urlsock
{

struct ITxJobManagerMock : public ITxJobManager
{
    MOCK_METHOD1(getITxJobByIpPortMessageId, std::shared_ptr<ITxJob>(IpPortMessageId));
    MOCK_METHOD2(createITxJob, void(IpPortMessageId, std::shared_ptr<ITxJob>&));
    MOCK_METHOD1(deleteITxJob, void(IpPortMessageId));
    MOCK_METHOD2(reportAck, void(IpPortMessageId, uint32_t offset));
    MOCK_METHOD3(reportNack, void(IpPortMessageId, uint32_t offset, ENackReason));


};

} // namespace urlsock

#endif
 