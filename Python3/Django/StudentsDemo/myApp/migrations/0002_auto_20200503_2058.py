# Generated by Django 3.0.5 on 2020-05-03 12:58

from django.db import migrations, models
import django.db.models.manager
import tinymce.models


class Migration(migrations.Migration):

    dependencies = [
        ('myApp', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='MCE_Text',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('str', tinymce.models.HTMLField()),
            ],
        ),
        migrations.AlterModelOptions(
            name='students',
            options={'ordering': ['id']},
        ),
        migrations.AlterModelManagers(
            name='students',
            managers=[
                ('stu_all', django.db.models.manager.Manager()),
            ],
        ),
        migrations.AlterModelTable(
            name='students',
            table='myApp_students',
        ),
    ]
