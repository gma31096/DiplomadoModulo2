
(cl:in-package :asdf)

(defsystem "clips_ros-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "planning_cmd" :depends-on ("_package_planning_cmd"))
    (:file "_package_planning_cmd" :depends-on ("_package"))
    (:file "StrQueryKDB" :depends-on ("_package_StrQueryKDB"))
    (:file "_package_StrQueryKDB" :depends-on ("_package"))
    (:file "InitKDB" :depends-on ("_package_InitKDB"))
    (:file "_package_InitKDB" :depends-on ("_package"))
    (:file "clearKDB" :depends-on ("_package_clearKDB"))
    (:file "_package_clearKDB" :depends-on ("_package"))
  ))