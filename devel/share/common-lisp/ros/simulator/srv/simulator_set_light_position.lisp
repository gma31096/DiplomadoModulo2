; Auto-generated. Do not edit!


(cl:in-package simulator-srv)


;//! \htmlinclude simulator_set_light_position-request.msg.html

(cl:defclass <simulator_set_light_position-request> (roslisp-msg-protocol:ros-message)
  ((light_x
    :reader light_x
    :initarg :light_x
    :type cl:float
    :initform 0.0)
   (light_y
    :reader light_y
    :initarg :light_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass simulator_set_light_position-request (<simulator_set_light_position-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_set_light_position-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_set_light_position-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_set_light_position-request> is deprecated: use simulator-srv:simulator_set_light_position-request instead.")))

(cl:ensure-generic-function 'light_x-val :lambda-list '(m))
(cl:defmethod light_x-val ((m <simulator_set_light_position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:light_x-val is deprecated.  Use simulator-srv:light_x instead.")
  (light_x m))

(cl:ensure-generic-function 'light_y-val :lambda-list '(m))
(cl:defmethod light_y-val ((m <simulator_set_light_position-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:light_y-val is deprecated.  Use simulator-srv:light_y instead.")
  (light_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_set_light_position-request>) ostream)
  "Serializes a message object of type '<simulator_set_light_position-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'light_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'light_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_set_light_position-request>) istream)
  "Deserializes a message object of type '<simulator_set_light_position-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'light_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'light_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_set_light_position-request>)))
  "Returns string type for a service object of type '<simulator_set_light_position-request>"
  "simulator/simulator_set_light_positionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_set_light_position-request)))
  "Returns string type for a service object of type 'simulator_set_light_position-request"
  "simulator/simulator_set_light_positionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_set_light_position-request>)))
  "Returns md5sum for a message object of type '<simulator_set_light_position-request>"
  "d56d73ee632c8aa7c9431df2ebbb2712")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_set_light_position-request)))
  "Returns md5sum for a message object of type 'simulator_set_light_position-request"
  "d56d73ee632c8aa7c9431df2ebbb2712")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_set_light_position-request>)))
  "Returns full string definition for message of type '<simulator_set_light_position-request>"
  (cl:format cl:nil "float32 light_x~%float32 light_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_set_light_position-request)))
  "Returns full string definition for message of type 'simulator_set_light_position-request"
  (cl:format cl:nil "float32 light_x~%float32 light_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_set_light_position-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_set_light_position-request>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_set_light_position-request
    (cl:cons ':light_x (light_x msg))
    (cl:cons ':light_y (light_y msg))
))
;//! \htmlinclude simulator_set_light_position-response.msg.html

(cl:defclass <simulator_set_light_position-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass simulator_set_light_position-response (<simulator_set_light_position-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_set_light_position-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_set_light_position-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_set_light_position-response> is deprecated: use simulator-srv:simulator_set_light_position-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <simulator_set_light_position-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:success-val is deprecated.  Use simulator-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_set_light_position-response>) ostream)
  "Serializes a message object of type '<simulator_set_light_position-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_set_light_position-response>) istream)
  "Deserializes a message object of type '<simulator_set_light_position-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_set_light_position-response>)))
  "Returns string type for a service object of type '<simulator_set_light_position-response>"
  "simulator/simulator_set_light_positionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_set_light_position-response)))
  "Returns string type for a service object of type 'simulator_set_light_position-response"
  "simulator/simulator_set_light_positionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_set_light_position-response>)))
  "Returns md5sum for a message object of type '<simulator_set_light_position-response>"
  "d56d73ee632c8aa7c9431df2ebbb2712")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_set_light_position-response)))
  "Returns md5sum for a message object of type 'simulator_set_light_position-response"
  "d56d73ee632c8aa7c9431df2ebbb2712")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_set_light_position-response>)))
  "Returns full string definition for message of type '<simulator_set_light_position-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_set_light_position-response)))
  "Returns full string definition for message of type 'simulator_set_light_position-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_set_light_position-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_set_light_position-response>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_set_light_position-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'simulator_set_light_position)))
  'simulator_set_light_position-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'simulator_set_light_position)))
  'simulator_set_light_position-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_set_light_position)))
  "Returns string type for a service object of type '<simulator_set_light_position>"
  "simulator/simulator_set_light_position")