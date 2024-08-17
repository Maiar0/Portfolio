from bson.objectid import ObjectId
from pymongo import MongoClient


class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self, username, password):
        # Initializing the MongoClient to access the MongoDB databases and collections.
        USER = username #'aacuser'
        PASS = password #'SNHU1234'
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 31932
        DB = 'aac'
        COL = 'animals'

        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
        self.database = self.client['%s' % (DB)]
        self.collection = self.database['%s' % (COL)]

    def create(self, data):
        """Insert a document into the collection"""
        if data:
            result = self.collection.insert_one(data)
            return bool(result.acknowledged)
        else:
            raise ValueError("Data parameter is empty")

    def read(self, query=None):
        """Query for documents in the collection"""
        if query is None:
            query = {}
        cursor = self.collection.find(query)
        return list(cursor)

    def update(self, query, update_data):
        """Update documents in the collection"""
        if query and update_data:
            result = self.collection.update_many(query, {'$set': update_data})
            return result.modified_count > 0
        else:
            raise ValueError("Query or update_data parameter is empty")

    def delete(self, query):
        """Delete documents from the collection"""
        if query:
            result = self.collection.delete_many(query)
            return result.deleted_count > 0
        else:
            raise ValueError("Query parameter is empty")
