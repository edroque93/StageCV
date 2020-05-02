#include <iostream>
#include <opencv2/opencv.hpp>
#include "VideoCaptureStage.hpp"
#include "ScaleStage.hpp"
#include "HueFilterStage.hpp"
#include "BlurStage.hpp"
#include "ContourDetectionStage.hpp"
#include "ContourPlotStage.hpp"

int main(int argc, char** argv )
{
    VideoCaptureStage vcs;
    ScaleStage ss(vcs, 320, 240);
    BlurStage bs(ss, 37);
    HueFilterStage hfs(bs, 60, 15);
    ContourDetectionStage cds(hfs);
    ContourPlotStage cps(vcs, cds);

    for(;;)
    {
        cps.Execute();

        cv::imshow("VCS", vcs.GetOutputImage());
        cv::imshow("SS", ss.GetOutputImage());
        cv::imshow("BS", bs.GetOutputImage());
        cv::imshow("HFS", hfs.GetOutputImage());
        cv::imshow("CPS", cps.GetOutputImage());

        if (cv::waitKey(1) > 0) break;
    }

    return 0;
}
