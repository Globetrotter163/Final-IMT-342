# generated from rosidl_generator_py/resource/_idl.py.em
# with input from warehouse_interfaces:msg/ProductRecord.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ProductRecord(type):
    """Metaclass of message 'ProductRecord'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('warehouse_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'warehouse_interfaces.msg.ProductRecord')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__product_record
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__product_record
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__product_record
            cls._TYPE_SUPPORT = module.type_support_msg__msg__product_record
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__product_record

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ProductRecord(metaclass=Metaclass_ProductRecord):
    """Message class 'ProductRecord'."""

    __slots__ = [
        '_product_id',
        '_name',
        '_barcode',
        '_quantity',
        '_unit',
        '_weight',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'product_id': 'string',
        'name': 'string',
        'barcode': 'string',
        'quantity': 'uint32',
        'unit': 'string',
        'weight': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.product_id = kwargs.get('product_id', str())
        self.name = kwargs.get('name', str())
        self.barcode = kwargs.get('barcode', str())
        self.quantity = kwargs.get('quantity', int())
        self.unit = kwargs.get('unit', str())
        self.weight = kwargs.get('weight', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.product_id != other.product_id:
            return False
        if self.name != other.name:
            return False
        if self.barcode != other.barcode:
            return False
        if self.quantity != other.quantity:
            return False
        if self.unit != other.unit:
            return False
        if self.weight != other.weight:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def product_id(self):
        """Message field 'product_id'."""
        return self._product_id

    @product_id.setter
    def product_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'product_id' field must be of type 'str'"
        self._product_id = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def barcode(self):
        """Message field 'barcode'."""
        return self._barcode

    @barcode.setter
    def barcode(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'barcode' field must be of type 'str'"
        self._barcode = value

    @builtins.property
    def quantity(self):
        """Message field 'quantity'."""
        return self._quantity

    @quantity.setter
    def quantity(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'quantity' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'quantity' field must be an unsigned integer in [0, 4294967295]"
        self._quantity = value

    @builtins.property
    def unit(self):
        """Message field 'unit'."""
        return self._unit

    @unit.setter
    def unit(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'unit' field must be of type 'str'"
        self._unit = value

    @builtins.property
    def weight(self):
        """Message field 'weight'."""
        return self._weight

    @weight.setter
    def weight(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'weight' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'weight' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._weight = value
