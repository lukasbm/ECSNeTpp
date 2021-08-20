#ifndef COMMON_SIMULATIONCONTROLLER_H_
#define COMMON_SIMULATIONCONTROLLER_H_

#include "omnetpp.h"
#include "../stask/ISTask.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class SimulationController : public cSimpleModule, public cListener
    {
    protected:
        long packetCountLimit;
        long packetCount = 0;
        long sourcePacketCount = 0;
        bool enableLimitFromSource;
        bool stopEventGeneration;
        bool stopEdgeIdleEnergyRecording;
        simtime_t startTime = -1;

    public:
        static simsignal_t totalSimTimeChangedSignal;

    public:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual bool getStopEventGeneration();
        virtual bool getStopEdgeIdleEnergyRecording();
        //    SimulationController();
        //    virtual ~SimulationController();
        virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj, cObject *details) override;
        virtual void receiveSignal(cComponent *source, simsignal_t signalID, long value, cObject *details) override;
    };

} /* namespace ecsnetpp */

#endif /* COMMON_SIMULATIONCONTROLLER_H_ */
