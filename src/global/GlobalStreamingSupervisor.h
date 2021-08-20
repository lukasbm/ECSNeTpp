#ifndef GLOBAL_GLOBALSTREAMINGSUPERVISOR_H_
#define GLOBAL_GLOBALSTREAMINGSUPERVISOR_H_

#include "omnetpp.h"
#include "../msg/StreamingMessage_m.h"
#include "inet/networklayer/common/L3Address.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UDPSocket.h"

//using namespace inet;
using namespace omnetpp;

namespace ecsnetpp
{

    class GlobalStreamingSupervisor : public cSimpleModule
    {
    private:
        inet::UDPSocket socket;
        cMessage *bindMsg = nullptr;
        std::map<std::string, std::vector<std::string>> senderStaskCategoryToDownstreamNodeMap;
        std::map<std::string, std::vector<inet::L3Address>> senderStaskCategoryToDownstreamNodeIPMap;

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        virtual void addSTaskCategoryToDownstreamNodeMapping(
            std::string senderSTaskCategory,
            std::string downstreamNodeFullPath);
        virtual void addSTaskCategoryToDownstreamNodeMapping(
            std::string senderSTaskCategory,
            std::vector<std::string> downstreamNodeFullPaths);
        virtual void resolveDownstreamNodeIPs();
        //    GlobalStreamingSupervisor();
        //    virtual ~GlobalStreamingSupervisor();
    };

} /* namespace ecsnetpp */

#endif /* GLOBAL_GLOBALSTREAMINGSUPERVISOR_H_ */
