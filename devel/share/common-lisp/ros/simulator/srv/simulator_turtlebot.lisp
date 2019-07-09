; Auto-generated. Do not edit!


(cl:in-package simulator-srv)


;//! \htmlinclude simulator_turtlebot-request.msg.html

(cl:defclass <simulator_turtlebot-request> (roslisp-msg-protocol:ros-message)
  ((theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0)
   (distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass simulator_turtlebot-request (<simulator_turtlebot-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_turtlebot-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_turtlebot-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_turtlebot-request> is deprecated: use simulator-srv:simulator_turtlebot-request instead.")))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <simulator_turtlebot-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:theta-val is deprecated.  Use simulator-srv:theta instead.")
  (theta m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <simulator_turtlebot-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:distance-val is deprecated.  Use simulator-srv:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_turtlebot-request>) ostream)
  "Serializes a message object of type '<simulator_turtlebot-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_turtlebot-request>) istream)
  "Deserializes a message object of type '<simulator_turtlebot-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'theta) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_turtlebot-request>)))
  "Returns string type for a service object of type '<simulator_turtlebot-request>"
  "simulator/simulator_turtlebotRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_turtlebot-request)))
  "Returns string type for a service object of type 'simulator_turtlebot-request"
  "simulator/simulator_turtlebotRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_turtlebot-request>)))
  "Returns md5sum for a message object of type '<simulator_turtlebot-request>"
  "f6c91c9ac3aa81fb2b1334bdb82aee4d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_turtlebot-request)))
  "Returns md5sum for a message object of type 'simulator_turtlebot-request"
  "f6c91c9ac3aa81fb2b1334bdb82aee4d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_turtlebot-request>)))
  "Returns full string definition for message of type '<simulator_turtlebot-request>"
  (cl:format cl:nil "float32 theta~%float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_turtlebot-request)))
  "Returns full string definition for message of type 'simulator_turtlebot-request"
  (cl:format cl:nil "float32 theta~%float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_turtlebot-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_turtlebot-request>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_turtlebot-request
    (cl:cons ':theta (theta msg))
    (cl:cons ':distance (distance msg))
))
;//! \htmlinclude simulator_turtlebot-response.msg.html

(cl:defclass <simulator_turtlebot-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:float
    :initform 0.0))
)

(cl:defclass simulator_turtlebot-response (<simulator_turtlebot-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_turtlebot-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_turtlebot-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_turtlebot-response> is deprecated: use simulator-srv:simulator_turtlebot-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <simulator_turtlebot-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:done-val is deprecated.  Use simulator-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_turtlebot-response>) ostream)
  "Serializes a message object of type '<simulator_turtlebot-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'done))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_turtlebot-response>) istream)
  "Deserializes a message object of type '<simulator_turtlebot-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'done) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_turtlebot-response>)))
  "Returns string type for a service object of type '<simulator_turtlebot-response>"
  "simulator/simulator_turtlebotResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_turtlebot-response)))
  "Returns string type for a service object of type 'simulator_turtlebot-response"
  "simulator/simulator_turtlebotResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_turtlebot-response>)))
  "Returns md5sum for a message object of type '<simulator_turtlebot-response>"
  "f6c91c9ac3aa81fb2b1334bdb82aee4d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_turtlebot-response)))
  "Returns md5sum for a message object of type 'simulator_turtlebot-response"
  "f6c91c9ac3aa81fb2b1334bdb82aee4d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_turtlebot-response>)))
  "Returns full string definition for message of type '<simulator_turtlebot-response>"
  (cl:format cl:nil "float32 done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_turtlebot-response)))
  "Returns full string definition for message of type 'simulator_turtlebot-response"
  (cl:format cl:nil "float32 done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_turtlebot-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_turtlebot-response>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_turtlebot-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'simulator_turtlebot)))
  'simulator_turtlebot-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'simulator_turtlebot)))
  'simulator_turtlebot-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_turtlebot)))
  "Returns string type for a service object of type '<simulator_turtlebot>"
  "simulator/simulator_turtlebot")