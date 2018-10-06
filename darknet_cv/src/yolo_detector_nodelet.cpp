/*
 yolo_detector_nodelet.cpp

 Copyright (C) 2018 Alessandro Francescon

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include "yolo_detector.h"

namespace darknet_cv {

    class YoloDetectorNodelet : public nodelet::Nodelet {

        public:

            YoloDetectorNodelet() {};

        private:

            virtual void onInit() {

                // Get node handle
                ros::NodeHandle nodeHandle = getNodeHandle();
                ros::NodeHandle privateNodeHanlde = getPrivateNodeHandle();

                // Create yolo detector
                yoloDetector.reset(new YoloDetector(nodeHandle, privateNodeHanlde));

                // Init yolo detector
                yoloDetector->init();

            }

            boost::shared_ptr<YoloDetector> yoloDetector;

    };

}

PLUGINLIB_DECLARE_CLASS(darknet_cv, YoloDetectorNodelet, darknet_cv::YoloDetectorNodelet, nodelet::Nodelet);


