---------------------------------- City ----------------------------------------
import unittest
from models.city import City
from models.base_model import BaseModel
from datetime import datetime

class TestCity(unittest.TestCase):
    """Test cases for the City class"""

    def setUp(self):
        """Set up a new City instance for testing"""
        self.city = City()

    def test_inheritance(self):
        """Test if City class inherits from BaseModel"""
        self.assertIsInstance(self.city, BaseModel)

    def test_attributes_exist(self):
        """Test that City has all required attributes"""
        self.assertTrue(hasattr(self.city, "state_id"))
        self.assertTrue(hasattr(self.city, "name"))

    def test_attributes_default_value(self):
        """Test the default value of City attributes"""
        self.assertEqual(self.city.state_id, "")
        self.assertEqual(self.city.name, "")

    def test_instance_creation(self):
        """Test if City instance is created with unique ID and timestamps"""
        self.assertIsInstance(self.city.id, str)
        self.assertIsInstance(self.city.created_at, datetime)
        self.assertIsInstance(self.city.updated_at, datetime)

    def test_to_dict(self):
        """Test to_dict method to include City attributes and base ones"""
        city_dict = self.city.to_dict()
        self.assertIn("state_id", city_dict)
        self.assertIn("name", city_dict)
        self.assertIn("__class__", city_dict)
        self.assertEqual(city_dict["__class__"], "City")

    def test_str_method(self):
        """Test __str__ method returns the correct format"""
        expected = f"[City] ({self.city.id}) {self.city.__dict__}"
        self.assertEqual(str(self.city), expected)

    def test_save_method(self):
        """Test if save method updates the updated_at attribute"""
        old_updated_at = self.city.updated_at
        self.city.save()
        self.assertNotEqual(self.city.updated_at, old_updated_at)
        self.assertTrue(self.city.updated_at > old_updated_at)

if __name__ == '__main__':
    unittest.main()

-------------------------------------- Amenity ----------------------------------------------

import unittest
from models.amenity import Amenity
from models.base_model import BaseModel
from datetime import datetime

class TestAmenity(unittest.TestCase):
    """Test cases for the Amenity class"""

    def setUp(self):
        """Set up a new Amenity instance for testing"""
        self.amenity = Amenity()

    def test_inheritance(self):
        """Test if Amenity class inherits from BaseModel"""
        self.assertIsInstance(self.amenity, BaseModel)

    def test_attributes_exist(self):
        """Test that Amenity has the required attribute"""
        self.assertTrue(hasattr(self.amenity, "name"))

    def test_attributes_default_value(self):
        """Test the default value of Amenity's attributes"""
        self.assertEqual(self.amenity.name, "")

    def test_instance_creation(self):
        """Test if Amenity instance is created with unique ID and timestamps"""
        self.assertIsInstance(self.amenity.id, str)
        self.assertIsInstance(self.amenity.created_at, datetime)
        self.assertIsInstance(self.amenity.updated_at, datetime)

    def test_to_dict(self):
        """Test to_dict method to include Amenity attributes and base ones"""
        amenity_dict = self.amenity.to_dict()
        self.assertIn("name", amenity_dict)
        self.assertIn("__class__", amenity_dict)
        self.assertEqual(amenity_dict["__class__"], "Amenity")

    def test_str_method(self):
        """Test __str__ method returns the correct format"""
        expected = f"[Amenity] ({self.amenity.id}) {self.amenity.__dict__}"
        self.assertEqual(str(self.amenity), expected)

    def test_save_method(self):
        """Test if save method updates the updated_at attribute"""
        old_updated_at = self.amenity.updated_at
        self.amenity.save()
        self.assertNotEqual(self.amenity.updated_at, old_updated_at)
        self.assertTrue(self.amenity.updated_at > old_updated_at)

if __name__ == '__main__':
    unittest.main()

------------------------------------------ Place -----------------------------------------------

import unittest
from models.place import Place
from models.base_model import BaseModel
from datetime import datetime

class TestPlace(unittest.TestCase):
    """Test cases for the Place class"""

    def setUp(self):
        """Set up a new Place instance for testing"""
        self.place = Place()

    def test_inheritance(self):
        """Test if Place class inherits from BaseModel"""
        self.assertIsInstance(self.place, BaseModel)

    def test_attributes_exist(self):
        """Test that Place has all required attributes"""
        self.assertTrue(hasattr(self.place, "city_id"))
        self.assertTrue(hasattr(self.place, "user_id"))
        self.assertTrue(hasattr(self.place, "name"))
        self.assertTrue(hasattr(self.place, "description"))
        self.assertTrue(hasattr(self.place, "number_rooms"))
        self.assertTrue(hasattr(self.place, "number_bathrooms"))
        self.assertTrue(hasattr(self.place, "max_guest"))
        self.assertTrue(hasattr(self.place, "price_by_night"))
        self.assertTrue(hasattr(self.place, "latitude"))
        self.assertTrue(hasattr(self.place, "longitude"))
        self.assertTrue(hasattr(self.place, "amenity_ids"))

    def test_attributes_default_value(self):
        """Test the default value of Place attributes"""
        self.assertEqual(self.place.city_id, "")
        self.assertEqual(self.place.user_id, "")
        self.assertEqual(self.place.name, "")
        self.assertEqual(self.place.description, "")
        self.assertEqual(self.place.number_rooms, 0)
        self.assertEqual(self.place.number_bathrooms, 0)
        self.assertEqual(self.place.max_guest, 0)
        self.assertEqual(self.place.price_by_night, 0)
        self.assertEqual(self.place.latitude, 0.0)
        self.assertEqual(self.place.longitude, 0.0)
        self.assertEqual(self.place.amenity_ids, [])

    def test_instance_creation(self):
        """Test if Place instance is created with unique ID and timestamps"""
        self.assertIsInstance(self.place.id, str)
        self.assertIsInstance(self.place.created_at, datetime)
        self.assertIsInstance(self.place.updated_at, datetime)

    def test_to_dict(self):
        """Test to_dict method to include Place attributes and base ones"""
        place_dict = self.place.to_dict()
        self.assertIn("city_id", place_dict)
        self.assertIn("user_id", place_dict)
        self.assertIn("name", place_dict)
        self.assertIn("description", place_dict)
        self.assertIn("number_rooms", place_dict)
        self.assertIn("number_bathrooms", place_dict)
        self.assertIn("max_guest", place_dict)
        self.assertIn("price_by_night", place_dict)
        self.assertIn("latitude", place_dict)
        self.assertIn("longitude", place_dict)
        self.assertIn("amenity_ids", place_dict)
        self.assertIn("__class__", place_dict)
        self.assertEqual(place_dict["__class__"], "Place")

    def test_str_method(self):
        """Test __str__ method returns the correct format"""
        expected = f"[Place] ({self.place.id}) {self.place.__dict__}"
        self.assertEqual(str(self.place), expected)

    def test_save_method(self):
        """Test if save method updates the updated_at attribute"""
        old_updated_at = self.place.updated_at
        self.place.save()
        self.assertNotEqual(self.place.updated_at, old_updated_at)
        self.assertTrue(self.place.updated_at > old_updated_at)

    def test_default_values_after_save(self):
        """Test if the default values persist after save"""
        self.place.save()
        place_dict = self.place.to_dict()
        self.assertEqual(place_dict['city_id'], "")
        self.assertEqual(place_dict['user_id'], "")
        self.assertEqual(place_dict['name'], "")
        self.assertEqual(place_dict['description'], "")
        self.assertEqual(place_dict['number_rooms'], 0)
        self.assertEqual(place_dict['number_bathrooms'], 0)
        self.assertEqual(place_dict['max_guest'], 0)
        self.assertEqual(place_dict['price_by_night'], 0)
        self.assertEqual(place_dict['latitude'], 0.0)
        self.assertEqual(place_dict['longitude'], 0.0)
        self.assertEqual(place_dict['amenity_ids'], [])

if __name__ == '__main__':
    unittest.main()

------------------------------ Review --------------------------------------------

class TestReview(unittest.TestCase):
    """Test the Review class"""

    def test_instance_creation(self):
        """Test if an instance of Review can be created"""
        review = Review()
        self.assertIsInstance(review, Review)
        self.assertIsInstance(review, BaseModel)  # Review should inherit from BaseModel

    def test_default_values(self):
        """Test if the default values of Review are correct"""
        review = Review()
        self.assertEqual(review.place_id, "")  # Default value for place_id should be an empty string
        self.assertEqual(review.user_id, "")   # Default value for user_id should be an empty string
        self.assertEqual(review.text, "")      # Default value for text should be an empty string

    def test_inherited_attributes(self):
        """Test if the Review class correctly inherits attributes from BaseModel"""
        review = Review()
        # BaseModel has id and created_at, so those should be inherited
        self.assertTrue(hasattr(review, "id"))
        self.assertTrue(hasattr(review, "created_at"))
        self.assertTrue(hasattr(review, "updated_at"))

    def test_attribute_assignment(self):
        """Test if we can set attributes for Review instances"""
        review = Review()
        review.place_id = "12345"
        review.user_id = "67890"
        review.text = "Great place!"
        
        self.assertEqual(review.place_id, "12345")
        self.assertEqual(review.user_id, "67890")
        self.assertEqual(review.text, "Great place!")

    def test_save_method(self):
        """Test if the save method works for Review (inherited from BaseModel)"""
        review = Review()
        prev_updated_at = review.updated_at
        review.save()
        self.assertNotEqual(prev_updated_at, review.updated_at)  # updated_at should be updated after save

if __name__ == '__main__':
    unittest.main()
