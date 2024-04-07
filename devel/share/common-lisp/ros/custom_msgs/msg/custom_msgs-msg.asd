
(cl:in-package :asdf)

(defsystem "custom_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :jsk_recognition_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "DetectedObject" :depends-on ("_package_DetectedObject"))
    (:file "_package_DetectedObject" :depends-on ("_package"))
    (:file "DetectedObjectArray" :depends-on ("_package_DetectedObjectArray"))
    (:file "_package_DetectedObjectArray" :depends-on ("_package"))
    (:file "MOT" :depends-on ("_package_MOT"))
    (:file "_package_MOT" :depends-on ("_package"))
    (:file "TrajPredArray" :depends-on ("_package_TrajPredArray"))
    (:file "_package_TrajPredArray" :depends-on ("_package"))
    (:file "TrajPredSingle" :depends-on ("_package_TrajPredSingle"))
    (:file "_package_TrajPredSingle" :depends-on ("_package"))
  ))