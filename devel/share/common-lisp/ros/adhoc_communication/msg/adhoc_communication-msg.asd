
(cl:in-package :asdf)

(defsystem "adhoc_communication-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :nav_msgs-msg
)
  :components ((:file "_package")
    (:file "CMgrDimensions" :depends-on ("_package_CMgrDimensions"))
    (:file "_package_CMgrDimensions" :depends-on ("_package"))
    (:file "CMgrRobotUpdate" :depends-on ("_package_CMgrRobotUpdate"))
    (:file "_package_CMgrRobotUpdate" :depends-on ("_package"))
    (:file "ExpAuction" :depends-on ("_package_ExpAuction"))
    (:file "_package_ExpAuction" :depends-on ("_package"))
    (:file "ExpAuctionElement" :depends-on ("_package_ExpAuctionElement"))
    (:file "_package_ExpAuctionElement" :depends-on ("_package"))
    (:file "ExpCluster" :depends-on ("_package_ExpCluster"))
    (:file "_package_ExpCluster" :depends-on ("_package"))
    (:file "ExpClusterElement" :depends-on ("_package_ExpClusterElement"))
    (:file "_package_ExpClusterElement" :depends-on ("_package"))
    (:file "ExpFrontier" :depends-on ("_package_ExpFrontier"))
    (:file "_package_ExpFrontier" :depends-on ("_package"))
    (:file "ExpFrontierElement" :depends-on ("_package_ExpFrontierElement"))
    (:file "_package_ExpFrontierElement" :depends-on ("_package"))
    (:file "MmControl" :depends-on ("_package_MmControl"))
    (:file "_package_MmControl" :depends-on ("_package"))
    (:file "MmListOfPoints" :depends-on ("_package_MmListOfPoints"))
    (:file "_package_MmListOfPoints" :depends-on ("_package"))
    (:file "MmMapUpdate" :depends-on ("_package_MmMapUpdate"))
    (:file "_package_MmMapUpdate" :depends-on ("_package"))
    (:file "MmPoint" :depends-on ("_package_MmPoint"))
    (:file "_package_MmPoint" :depends-on ("_package"))
    (:file "MmRobotPosition" :depends-on ("_package_MmRobotPosition"))
    (:file "_package_MmRobotPosition" :depends-on ("_package"))
    (:file "RecvString" :depends-on ("_package_RecvString"))
    (:file "_package_RecvString" :depends-on ("_package"))
  ))