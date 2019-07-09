; Auto-generated. Do not edit!


(cl:in-package simulator-srv)


;//! \htmlinclude simulator_object_interaction-request.msg.html

(cl:defclass <simulator_object_interaction-request> (roslisp-msg-protocol:ros-message)
  ((grasp
    :reader grasp
    :initarg :grasp
    :type cl:integer
    :initform 0)
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform ""))
)

(cl:defclass simulator_object_interaction-request (<simulator_object_interaction-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_object_interaction-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_object_interaction-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_object_interaction-request> is deprecated: use simulator-srv:simulator_object_interaction-request instead.")))

(cl:ensure-generic-function 'grasp-val :lambda-list '(m))
(cl:defmethod grasp-val ((m <simulator_object_interaction-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:grasp-val is deprecated.  Use simulator-srv:grasp instead.")
  (grasp m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <simulator_object_interaction-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:name-val is deprecated.  Use simulator-srv:name instead.")
  (name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_object_interaction-request>) ostream)
  "Serializes a message object of type '<simulator_object_interaction-request>"
  (cl:let* ((signed (cl:slot-value msg 'grasp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_object_interaction-request>) istream)
  "Deserializes a message object of type '<simulator_object_interaction-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'grasp) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_object_interaction-request>)))
  "Returns string type for a service object of type '<simulator_object_interaction-request>"
  "simulator/simulator_object_interactionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_object_interaction-request)))
  "Returns string type for a service object of type 'simulator_object_interaction-request"
  "simulator/simulator_object_interactionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_object_interaction-request>)))
  "Returns md5sum for a message object of type '<simulator_object_interaction-request>"
  "5f2d08a4b7005ec192d2f5e0b480a776")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_object_interaction-request)))
  "Returns md5sum for a message object of type 'simulator_object_interaction-request"
  "5f2d08a4b7005ec192d2f5e0b480a776")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_object_interaction-request>)))
  "Returns full string definition for message of type '<simulator_object_interaction-request>"
  (cl:format cl:nil "int32 grasp~%string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_object_interaction-request)))
  "Returns full string definition for message of type 'simulator_object_interaction-request"
  (cl:format cl:nil "int32 grasp~%string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_object_interaction-request>))
  (cl:+ 0
     4
     4 (cl:length (cl:slot-value msg 'name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_object_interaction-request>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_object_interaction-request
    (cl:cons ':grasp (grasp msg))
    (cl:cons ':name (name msg))
))
;//! \htmlinclude simulator_object_interaction-response.msg.html

(cl:defclass <simulator_object_interaction-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass simulator_object_interaction-response (<simulator_object_interaction-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <simulator_object_interaction-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'simulator_object_interaction-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simulator-srv:<simulator_object_interaction-response> is deprecated: use simulator-srv:simulator_object_interaction-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <simulator_object_interaction-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simulator-srv:done-val is deprecated.  Use simulator-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <simulator_object_interaction-response>) ostream)
  "Serializes a message object of type '<simulator_object_interaction-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <simulator_object_interaction-response>) istream)
  "Deserializes a message object of type '<simulator_object_interaction-response>"
    (cl:setf (cl:slot-value msg 'done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<simulator_object_interaction-response>)))
  "Returns string type for a service object of type '<simulator_object_interaction-response>"
  "simulator/simulator_object_interactionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_object_interaction-response)))
  "Returns string type for a service object of type 'simulator_object_interaction-response"
  "simulator/simulator_object_interactionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<simulator_object_interaction-response>)))
  "Returns md5sum for a message object of type '<simulator_object_interaction-response>"
  "5f2d08a4b7005ec192d2f5e0b480a776")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'simulator_object_interaction-response)))
  "Returns md5sum for a message object of type 'simulator_object_interaction-response"
  "5f2d08a4b7005ec192d2f5e0b480a776")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<simulator_object_interaction-response>)))
  "Returns full string definition for message of type '<simulator_object_interaction-response>"
  (cl:format cl:nil "bool done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'simulator_object_interaction-response)))
  "Returns full string definition for message of type 'simulator_object_interaction-response"
  (cl:format cl:nil "bool done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <simulator_object_interaction-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <simulator_object_interaction-response>))
  "Converts a ROS message object to a list"
  (cl:list 'simulator_object_interaction-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'simulator_object_interaction)))
  'simulator_object_interaction-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'simulator_object_interaction)))
  'simulator_object_interaction-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'simulator_object_interaction)))
  "Returns string type for a service object of type '<simulator_object_interaction>"
  "simulator/simulator_object_interaction")