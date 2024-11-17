#!/usr/bin/python3

"""
test_base_model.py

This module provides a test class to test the `BaseModel` class
`base_model`.
"""

import unittest
from datetime import datetime
from models.base_model import BaseModel


class TestBaseModel(unittest.TestCase):

    def test_instance_creation(self):
        """Tests if a BaseModel instance is created correctly"""

        instance = BaseModel()
        self.assertIsInstance(instance, BaseModel)
        self.assertIsInstance(instance.id, str)
        self.assertIsInstance(instance.created_at, datetime)
        self.assertIsInstance(instance.updated_at, datetime)

    def test_unique_id(self):
        """Tests if `id` attribute has unique value for each instance"""

        instance1 = BaseModel()
        instance2 = BaseModel()
        self.assertNotEqual(instance1.id, instance2.id)

    def test_str(self):
        """Tests the output of the __str__ method"""

        instance = BaseModel()
        expected_str = "[BaseModel] ({}) {}".format(
                            instance.id, instance.__dict__)
        self.assertEqual(str(instance), expected_str)

    def test_save_method(self):
        """Tests if the updated_at attributed refreshes correctly"""

        instance = BaseModel()
        old_updated_at = instance.updated_at
        instance.save()
        self.assertNotEqual(instance.updated_at, old_updated_at)

    def test_to_dict_method(self):
        """Tests if to_dict returns the correct dictionary representation"""

        instance = BaseModel()
        self.assertIn('id', instance.to_dict())
        self.assertIn('created_at', instance.to_dict())
        self.assertIn('updated_at', instance.to_dict())
        self.assertIn('__class__', instance.to_dict())

    def test_kwargs(self):
        """Tests instantiation with kwargs"""

        instance = BaseModel()
        instance_dict = instance.to_dict()
        new_instance = BaseModel(**instance_dict)

        self.assertEqual(new_instance.id, instance.id)
        self.assertEqual(new_instance.created_at, instance.created_at)
        self.assertEqual(new_instance.updated_at, instance.updated_at)
        self.assertEqual(new_instance.to_dict(), instance.to_dict())

        # Test if BaseModel ignores unkown attributes in kwargs
        instance_dict = {
            'id': '1234'
            'created_at': '2024-11-08T12:00:00.000000'
            'updated_at': '2024-11-08T12:00:00.000000'
            'key': 'value'
        }

        instance = BaseModel(**instance_dict)
        self.assertFalse(hasattr(instance, 'key'))


if __name__ == '__main__':
    unittest.main()
