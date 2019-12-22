# -- coding: utf-8 --

from geolocation.main import GoogleMaps 
from geolocation.distance_matrix.client import DistanceMatrixApiClient

address = "New York City Wall Street 12"

google_maps = GoogleMaps(api_key='your_google_maps_key')

location = google_maps.search(location=address) # sends search to Google Maps.

print(location.all()) # returns all locations.

my_location = location.first() # returns only first location.

print(my_location.city) 
print(my_location.route) 
print(my_location.street_number) 
print(my_location.postal_code)


