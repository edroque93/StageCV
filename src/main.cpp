#include <iostream>
#include <opencv2/opencv.hpp>
#include "VideoCaptureStage.hpp"
#include "ScaleStage.hpp"
#include "HueFilterStage.hpp"
#include "BlurStage.hpp"

int main(int argc, char** argv )
{
    VideoCaptureStage vcs;
    ScaleStage ss(vcs, 320, 240);
    BlurStage bs(ss, 31);
    HueFilterStage hfs(bs, 60, 15);

    for(;;)
    {
        hfs.Execute();

        cv::imshow("VCS", vcs.GetOutputImage());
        cv::imshow("SS", ss.GetOutputImage());
        cv::imshow("BS", bs.GetOutputImage());
        cv::imshow("HFS", hfs.GetOutputImage());

        if (cv::waitKey(1) > 0) break;
    }

    return 0;
}
