; Auto-generated. Do not edit!


(cl:in-package simulator-srv)


;//! \htmlinclude simulator_stop-request.msg.html

(cl:defclass <simulator_stop-request> (roslisp-msg-protocol:ros-message)
  ((stop
    :reader stop
    :initarg :stop
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass simulator_stop-request (<simulator_stop-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_stop-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_stop-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_stop-request> is deprecated: use simulator-srv:simulator_stop-request instead.")))

(cl:ensure-generic-function 'stop-val :lambda-list '(m))
(cl:defmethod stop-val ((m <simulator_stop-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:stop-val is deprecated.  Use simulator-srv:stop instead.")
  (stop m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_stop-request>) ostream)
  "Serializes a message object of type '<simulator_stop-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'stop) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_stop-request>) istream)
  "Deserializes a message object of type '<simulator_stop-request>"
    (cl:setf (cl:slot-value msg 'stop) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_stop-request>)))
  "Returns string type for a service object of type '<simulator_stop-request>"
  "simulator/simulator_stopRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_stop-request)))
  "Returns string type for a service object of type 'simulator_stop-request"
  "simulator/simulator_stopRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_stop-request>)))
  "Returns md5sum for a message object of type '<simulator_stop-request>"
  "095e4397fe01973ad978411bb58eda37")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_stop-request)))
  "Returns md5sum for a message object of type 'simulator_stop-request"
  "095e4397fe01973ad978411bb58eda37")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_stop-request>)))
  "Returns full string definition for message of type '<simulator_stop-request>"
  (cl:format cl:nil "bool stop~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_stop-request)))
  "Returns full string definition for message of type 'simulator_stop-request"
  (cl:format cl:nil "bool stop~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_stop-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_stop-request>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_stop-request
    (cl:cons ':stop (stop msg))
))
;//! \htmlinclude simulator_stop-response.msg.html

(cl:defclass <simulator_stop-response> (roslisp-msg-protocol:ros-message)
  ((resp
    :reader resp
    :initarg :resp
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass simulator_stop-response (<simulator_stop-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_stop-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_stop-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_stop-response> is deprecated: use simulator-srv:simulator_stop-response instead.")))

(cl:ensure-generic-function 'resp-val :lambda-list '(m))
(cl:defmethod resp-val ((m <simulator_stop-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:resp-val is deprecated.  Use simulator-srv:resp instead.")
  (resp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_stop-response>) ostream)
  "Serializes a message object of type '<simulator_stop-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'resp) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_stop-response>) istream)
  "Deserializes a message object of type '<simulator_stop-response>"
    (cl:setf (cl:slot-value msg 'resp) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_stop-response>)))
  "Returns string type for a service object of type '<simulator_stop-response>"
  "simulator/simulator_stopResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_stop-response)))
  "Returns string type for a service object of type 'simulator_stop-response"
  "simulator/simulator_stopResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_stop-response>)))
  "Returns md5sum for a message object of type '<simulator_stop-response>"
  "095e4397fe01973ad978411bb58eda37")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_stop-response)))
  "Returns md5sum for a message object of type 'simulator_stop-response"
  "095e4397fe01973ad978411bb58eda37")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_stop-response>)))
  "Returns full string definition for message of type '<simulator_stop-response>"
  (cl:format cl:nil "bool resp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_stop-response)))
  "Returns full string definition for message of type 'simulator_stop-response"
  (cl:format cl:nil "bool resp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_stop-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_stop-response>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_stop-response
    (cl:cons ':resp (resp msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'simulator_stop)))
  'simulator_stop-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'simulator_stop)))
  'simulator_stop-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_stop)))
  "Returns string type for a service object of type '<simulator_stop>"
  "simulator/simulator_stop")