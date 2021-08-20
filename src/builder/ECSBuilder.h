#ifndef BUILDER_ECSBUILDER_H_
#define BUILDER_ECSBUILDER_H_

#include <omnetpp.h>
#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include "../global/GlobalStreamingSupervisor.h"
#include "../stask/StreamingSupervisor.h"

using namespace tinyxml2;

namespace ecsnetpp
{

    class ECSBuilder : public cSimpleModule
    {
        //public:
        //    ECSBuilder();
        //    virtual ~ECSBuilder();
    protected:
        GlobalStreamingSupervisor *globalSupervisor;
        bool ackersEnabled;
        bool hasGlobalSupervisor;

    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        void connect(cGate *src, cGate *dest, double delay, double ber, double datarate);
        void executeAllocationPlan(cModule *parent);
        void setupDistribution(XMLElement *task, const char *taskDistributionXmlElementName, const char *isDistributionEnabledBoolVarName,
                               const char *distributionModuleName, cModule *stask, cModule *_parent, const char *nonDistributedValueXmlElementName,
                               const char *nonDistributedValueVarName);
    };

} /* namespace ecsnetpp */

#endif /* BUILDER_ECSBUILDER_H_ */
