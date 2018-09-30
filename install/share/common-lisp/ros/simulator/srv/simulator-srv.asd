
(cl:in-package :asdf)

(defsystem "simulator-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "simulator_robot_laser_values" :depends-on ("_package_simulator_robot_laser_values"))
    (:file "_package_simulator_robot_laser_values" :depends-on ("_package"))
    (:file "simulator_base" :depends-on ("_package_simulator_base"))
    (:file "_package_simulator_base" :depends-on ("_package"))
    (:file "simulator_parameters" :depends-on ("_package_simulator_parameters"))
    (:file "_package_simulator_parameters" :depends-on ("_package"))
    (:file "simulator_robot_step" :depends-on ("_package_simulator_robot_step"))
    (:file "_package_simulator_robot_step" :depends-on ("_package"))
    (:file "simulator_laser" :depends-on ("_package_simulator_laser"))
    (:file "_package_simulator_laser" :depends-on ("_package"))
  ))