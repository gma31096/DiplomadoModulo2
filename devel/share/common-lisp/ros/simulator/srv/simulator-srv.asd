
(cl:in-package :asdf)

(defsystem "simulator-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "robot_step" :depends-on ("_package_robot_step"))
    (:file "_package_robot_step" :depends-on ("_package"))
  ))