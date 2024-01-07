
(cl:in-package :asdf)

(defsystem "custom_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MOT" :depends-on ("_package_MOT"))
    (:file "_package_MOT" :depends-on ("_package"))
  ))