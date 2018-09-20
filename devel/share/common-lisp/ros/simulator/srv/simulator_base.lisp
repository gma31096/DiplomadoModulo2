; Auto-generated. Do not edit!


(cl:in-package simulator-srv)


;//! \htmlinclude simulator_base-request.msg.html

(cl:defclass <simulator_base-request> (roslisp-msg-protocol:ros-message)
  ((theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0)
   (distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0)
   (x1
    :reader x1
    :initarg :x1
    :type cl:float
    :initform 0.0)
   (y1
    :reader y1
    :initarg :y1
    :type cl:float
    :initform 0.0)
   (new_simulation
    :reader new_simulation
    :initarg :new_simulation
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass simulator_base-request (<simulator_base-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_base-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_base-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_base-request> is deprecated: use simulator-srv:simulator_base-request instead.")))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <simulator_base-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:theta-val is deprecated.  Use simulator-srv:theta instead.")
  (theta m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <simulator_base-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:distance-val is deprecated.  Use simulator-srv:distance instead.")
  (distance m))

(cl:ensure-generic-function 'x1-val :lambda-list '(m))
(cl:defmethod x1-val ((m <simulator_base-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:x1-val is deprecated.  Use simulator-srv:x1 instead.")
  (x1 m))

(cl:ensure-generic-function 'y1-val :lambda-list '(m))
(cl:defmethod y1-val ((m <simulator_base-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:y1-val is deprecated.  Use simulator-srv:y1 instead.")
  (y1 m))

(cl:ensure-generic-function 'new_simulation-val :lambda-list '(m))
(cl:defmethod new_simulation-val ((m <simulator_base-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:new_simulation-val is deprecated.  Use simulator-srv:new_simulation instead.")
  (new_simulation m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_base-request>) ostream)
  "Serializes a message object of type '<simulator_base-request>"
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'new_simulation) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_base-request>) istream)
  "Deserializes a message object of type '<simulator_base-request>"
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'new_simulation) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_base-request>)))
  "Returns string type for a service object of type '<simulator_base-request>"
  "simulator/simulator_baseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_base-request)))
  "Returns string type for a service object of type 'simulator_base-request"
  "simulator/simulator_baseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_base-request>)))
  "Returns md5sum for a message object of type '<simulator_base-request>"
  "ec23e67bce036a9847d712ec6ce2eedb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_base-request)))
  "Returns md5sum for a message object of type 'simulator_base-request"
  "ec23e67bce036a9847d712ec6ce2eedb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_base-request>)))
  "Returns full string definition for message of type '<simulator_base-request>"
  (cl:format cl:nil "float32 theta~%float32 distance~%float32 x1~%float32 y1~%bool new_simulation~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_base-request)))
  "Returns full string definition for message of type 'simulator_base-request"
  (cl:format cl:nil "float32 theta~%float32 distance~%float32 x1~%float32 y1~%bool new_simulation~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_base-request>))
  (cl:+ 0
     4
     4
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_base-request>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_base-request
    (cl:cons ':theta (theta msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':x1 (x1 msg))
    (cl:cons ':y1 (y1 msg))
    (cl:cons ':new_simulation (new_simulation msg))
))
;//! \htmlinclude simulator_base-response.msg.html

(cl:defclass <simulator_base-response> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass simulator_base-response (<simulator_base-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_base-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_base-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_base-response> is deprecated: use simulator-srv:simulator_base-response instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <simulator_base-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:distance-val is deprecated.  Use simulator-srv:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_base-response>) ostream)
  "Serializes a message object of type '<simulator_base-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_base-response>) istream)
  "Deserializes a message object of type '<simulator_base-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_base-response>)))
  "Returns string type for a service object of type '<simulator_base-response>"
  "simulator/simulator_baseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_base-response)))
  "Returns string type for a service object of type 'simulator_base-response"
  "simulator/simulator_baseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_base-response>)))
  "Returns md5sum for a message object of type '<simulator_base-response>"
  "ec23e67bce036a9847d712ec6ce2eedb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_base-response)))
  "Returns md5sum for a message object of type 'simulator_base-response"
  "ec23e67bce036a9847d712ec6ce2eedb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_base-response>)))
  "Returns full string definition for message of type '<simulator_base-response>"
  (cl:format cl:nil "float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_base-response)))
  "Returns full string definition for message of type 'simulator_base-response"
  (cl:format cl:nil "float32 distance~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_base-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_base-response>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_base-response
    (cl:cons ':distance (distance msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'simulator_base)))
  'simulator_base-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'simulator_base)))
  'simulator_base-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_base)))
  "Returns string type for a service object of type '<simulator_base>"
  "simulator/simulator_base")