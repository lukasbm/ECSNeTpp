#ifndef STASK_STREAMINGSINK_H_
#define STASK_STREAMINGSINK_H_

#include "omnetpp.h"
#include "../msg/StreamingMessage_m.h"
#include "ISTask.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class StreamingSink : public ISTask
    {
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
    };

} /* namespace ecsnetpp */

#endif /* STASK_STREAMINGSINK_H_ */
