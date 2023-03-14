from django.db import models

# Create your models here.

class Idea(models.Model):
    title = models.CharField(max_length=255)
    description = models.TextField()
    youtube_url = models.URLField(null=True, blank=True)
    #status = models.CharField(
        #choices = ( ('pending','Waiting for review'),
        #            ('done','Done'),
        #            ('rejected','Idea rejected') ),
        #default = 'pending',
        #max_length = 30)
    
    def __str__(self):
        return self.title
