; Auto-generated. Do not edit!


(cl:in-package clips_ros-srv)


;//! \htmlinclude clearKDB-request.msg.html

(cl:defclass <clearKDB-request> (roslisp-msg-protocol:ros-message)
  ((clear
    :reader clear
    :initarg :clear
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass clearKDB-request (<clearKDB-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <clearKDB-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'clearKDB-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name clips_ros-srv:<clearKDB-request> is deprecated: use clips_ros-srv:clearKDB-request instead.")))

(cl:ensure-generic-function 'clear-val :lambda-list '(m))
(cl:defmethod clear-val ((m <clearKDB-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clips_ros-srv:clear-val is deprecated.  Use clips_ros-srv:clear instead.")
  (clear m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <clearKDB-request>) ostream)
  "Serializes a message object of type '<clearKDB-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'clear) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <clearKDB-request>) istream)
  "Deserializes a message object of type '<clearKDB-request>"
    (cl:setf (cl:slot-value msg 'clear) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<clearKDB-request>)))
  "Returns string type for a service object of type '<clearKDB-request>"
  "clips_ros/clearKDBRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'clearKDB-request)))
  "Returns string type for a service object of type 'clearKDB-request"
  "clips_ros/clearKDBRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<clearKDB-request>)))
  "Returns md5sum for a message object of type '<clearKDB-request>"
  "c0cba2f76fe2be4cac55cc053705feaa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'clearKDB-request)))
  "Returns md5sum for a message object of type 'clearKDB-request"
  "c0cba2f76fe2be4cac55cc053705feaa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<clearKDB-request>)))
  "Returns full string definition for message of type '<clearKDB-request>"
  (cl:format cl:nil "bool clear~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'clearKDB-request)))
  "Returns full string definition for message of type 'clearKDB-request"
  (cl:format cl:nil "bool clear~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <clearKDB-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <clearKDB-request>))
  "Converts a ROS message object to a list"
  (cl:list 'clearKDB-request
    (cl:cons ':clear (clear msg))
))
;//! \htmlinclude clearKDB-response.msg.html

(cl:defclass <clearKDB-response> (roslisp-msg-protocol:ros-message)
  ((cleared
    :reader cleared
    :initarg :cleared
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass clearKDB-response (<clearKDB-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <clearKDB-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'clearKDB-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name clips_ros-srv:<clearKDB-response> is deprecated: use clips_ros-srv:clearKDB-response instead.")))

(cl:ensure-generic-function 'cleared-val :lambda-list '(m))
(cl:defmethod cleared-val ((m <clearKDB-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clips_ros-srv:cleared-val is deprecated.  Use clips_ros-srv:cleared instead.")
  (cleared m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <clearKDB-response>) ostream)
  "Serializes a message object of type '<clearKDB-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'cleared) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <clearKDB-response>) istream)
  "Deserializes a message object of type '<clearKDB-response>"
    (cl:setf (cl:slot-value msg 'cleared) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<clearKDB-response>)))
  "Returns string type for a service object of type '<clearKDB-response>"
  "clips_ros/clearKDBResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'clearKDB-response)))
  "Returns string type for a service object of type 'clearKDB-response"
  "clips_ros/clearKDBResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<clearKDB-response>)))
  "Returns md5sum for a message object of type '<clearKDB-response>"
  "c0cba2f76fe2be4cac55cc053705feaa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'clearKDB-response)))
  "Returns md5sum for a message object of type 'clearKDB-response"
  "c0cba2f76fe2be4cac55cc053705feaa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<clearKDB-response>)))
  "Returns full string definition for message of type '<clearKDB-response>"
  (cl:format cl:nil "bool cleared~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'clearKDB-response)))
  "Returns full string definition for message of type 'clearKDB-response"
  (cl:format cl:nil "bool cleared~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <clearKDB-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <clearKDB-response>))
  "Converts a ROS message object to a list"
  (cl:list 'clearKDB-response
    (cl:cons ':cleared (cleared msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'clearKDB)))
  'clearKDB-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'clearKDB)))
  'clearKDB-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'clearKDB)))
  "Returns string type for a service object of type '<clearKDB>"
  "clips_ros/clearKDB")