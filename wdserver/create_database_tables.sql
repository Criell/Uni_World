create database Booking;
use Booking;

create table room(
    RNumber	INT AUTO_INCREMENT,
    Image TEXT NOT NULL,
  	hotel_name char(80) NOT NULL,
    RoomNumber INT NOT NULL,
    ReviewScore INT NOT NULL,
    Adults INT NOT NULL,
    kids INT NOT NULL,
    Location char(80) NOT NULL,
    Price char(80) NOT NULL,
    primary key (RNumber)
);

create table user_booking(
    BNumber	INT AUTO_INCREMENT,
  	Image TEXT NOT NULL,
    hotel_name char(80) NOT NULL,
    RoomNumber INT NOT NULL,
    ReviewScore INT NOT NULL,
    Check_in_Date char(80) NOT NULL,
    Check_in_Out char(80) NOT NULL,
    Adults INT NOT NULL,
    kids INT NOT NULL,
    Location char(80) NOT NULL,
    Price char(80) NOT NULL,
    primary key (BNumber)
);

create table booking_pay(
    PNumber	INT AUTO_INCREMENT,
  	Image TEXT NOT NULL,
    hotel_name char(80) NOT NULL,
    RoomNumber INT NOT NULL,
    ReviewScore INT NOT NULL,
    Check_in_Date char(80) NOT NULL,
    Check_in_Out char(80) NOT NULL,
    Adults INT NOT NULL,
    kids INT NOT NULL,
    Location char(80) NOT NULL,
    Price char(80) NOT NULL,
    primary key (PNumber)
);

create table users(
    UNumber	INT AUTO_INCREMENT,
	email TEXT NOT NULL,
    name char(80) NOT NULL,
    user_password TEXT NOT NULL,
    type char(80) NOT NULL,
	first_name char(80) NOT NULL,
    last_name char(80) NOT NULL,
    birthday char(80) NOT NULL,
    gender char(80) NOT NULL,
    phone INT NOT NULL,
    location char(80) NOT NULL,
	primary key(UNumber)
);

create table reviews(
    RevNumber INT AUTO_INCREMENT,
    hotel_name TEXT NOT NULL,
    rev_text TEXT NOT NULL,
    primary key(RevNumber)
);

INSERT INTO users (email, name, user_password, type, first_name, last_name, birthday, gender, phone, location) VALUES ("lina@email.com","Lina Guevara", "l123","User","Lina", "Guevara", "Dec20", "Female", 300899, "Colombia");
INSERT INTO users (email, name, user_password, type,  first_name, last_name, birthday, gender, phone, location)  VALUES ("diana@email.com","Diana Guevara","d123","User", "Diana", "Guevara", "Mar5", "Female", 300565, "Colombia");
INSERT INTO users (email, name, user_password, type,  first_name, last_name, birthday, gender, phone, location) VALUES ("silver@email.com","Silver Jewel Resort","l123","Hotel","Lina", "Guevara", "Dec20", "Female", 300899, "Colombia");
INSERT INTO users (email, name, user_password, type,  first_name, last_name, birthday, gender, phone, location) VALUES ("castle@email.com","Ebony Castle Hotel", "d123","Hotel","Diana", "Guevara", "Mar5", "Female", 300565, "Colombia");

INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price)  VALUES ("https://q-ec.bstatic.com/images/hotel/max1280x900/370/37024558.jpg", "Silver Jewel Resort", 6, 3, 1, 2, "brisbane, Australia", "USD 210");
INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price)  VALUES ("https://ritzcarlton-h.assetsadobe.com/is/image/content/dam/the-ritz-carlton/hotels/usa-and-canada/florida/miami-the-miami-beach-edition/guest-rooms/ED-MIAEB-07-new_RCMMBED_00024.png?$MedViewport100pct$", "Ebony Castle Hotel", 20, 4, 2,
3, "Melboune, Australia", "USD 176");
INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price)  VALUES ( "https://r-ec.bstatic.com/images/hotel/max1280x900/112/112782897.jpg", "White Lodge Hotel",3, 14, 3, 2, "Sydney, Australia", "USD 197");
INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price)  VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112779353.jpg", "Modest Seashore Hotel", 2, 10, 2, 2, "Canberra,Australia","USD 194");
INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price)  VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/104/104972556.jpg","Emerald Cabin Hotel", 3, 4, 3, 1, "Melboune, Australia", "USD 192");
INSERT INTO room (Image, hotel_name, RoomNumber, ReviewScore, Adults, kids, Location, Price)  VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/378/37858797.jpg", "Sunset Nebula Resort", 4, 8, 2, 1, "Melboune, Australia", "USD 226");
    
    
INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://ritzcarlton-h.assetsadobe.com/is/image/content/dam/the-ritz-carlton/hotels/usa-and-canada/florida/miami-the-miami-beach-edition/guest-rooms/ED-MIAEB-07-new_RCMMBED_00024.png?$MedViewport100pct$", "Emerald Hotel", 5, 18, "feb 2, 2018", "feb 15, 2018", 2, 1, "Canberra,Australia", "USD 212");
INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112782897.jpg", "Amenity Hotel", 3, 21, "Sep 2, 2018", "Sep 15, 2018", 2, 1, "Adelaide, Australia", "USD 191");
INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112779353.jpg", "Primal Pass Hotel", 4, 12, "Jun 2, 2018", "Jul 15, 2018", 1, 3, "Adelaide, Australia", "USD 174");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://ritzcarlton-h.assetsadobe.com/is/image/content/dam/the-ritz-carlton/hotels/usa-and-canada/florida/miami-the-miami-beach-edition/guest-rooms/ED-MIAEB-07-new_RCMMBED_00024.png?$MedViewport100pct$", "Emerald Hotel", 5, 18, "feb 2, 2018", "feb 15, 2018", 2, 1, "Canberra,Australia", "USD 212");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112782897.jpg", "Amenity Hotel", 3, 21, "Sep 2, 2018", "Sep 15, 2018", 2, 1, "Adelaide, Australia", "USD 191");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112779353.jpg", "Primal Pass Hotel", 4, 12, "Jun 2, 2018", "Jul 15, 2018", 1, 3, "Adelaide, Australia", "USD 174");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/104/104972556.jpg", "Revelation Resort",4, 16, "Nov 2, 2018", "Nov 15, 2018", 4, 1, "Hobart, Australia", "USD 168");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://r-ec.bstatic.com/images/hotel/max1280x900/378/37858797.jpg","Harborview Hotel",  2, 1, "Oct 2, 2018", "Oct 15, 2018", 4, 1, "Melboune, Australia", "USD 217");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ("https://ritzcarlton-h.assetsadobe.com/is/image/content/dam/the-ritz-carlton/hotels/usa-and-canada/florida/miami-the-miami-beach-edition/guest-rooms/ED-MIAEB-07-new_RCMMBED_00024.png?$MedViewport100pct$", "Majestic Hotel", 1, 15, "Jan 2, 2018", "Jan 15, 2018", 3, 2, "brisbane, Australia", "USD 153");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUES ( "https://q-ec.bstatic.com/images/hotel/max1280x900/370/37024541.jpg","Freedom Resort",10,5,"jan 5,2018","jan 7, 2018",2,3,"Hobart, Australia","USD 239");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://r-ec.bstatic.com/images/hotel/max1280x900/378/37858729.jpg", "recreation hoyel", 10,3,"feb 1, 2018","feb 4, 2018",4,3,"Adelaide, Australia", "USD 249");

INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://r-ec.bstatic.com/data/xphoto/max1024x768/314/31431686.jpg","Atlantis Shack Hotel",20,4,"jan 8, 2018", "jan 10, 2018", 2,3, "brisbane, Australia","USD 290");


INSERT INTO user_booking (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("http://www.bigyellowsuitcase.com.au/wp-content/uploads/2018/01/hotel-room.jpg", "Light Galaxy Hotel",13,5,"feb 6,2018","feb 8,2018",3,3, "Melboune, Australia","USD 192");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://fiestarancho.sclv.com/~/media/Images/Promotions/2017/January/FR-DeluxeKing.jpg?mw=460","Pacific Sword Hotel",14, 1,"may 2,2018","may 3,2018",4,2,"brisbane, Australia","USD 198");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://ritzcarlton-h.assetsadobe.com/is/image/content/dam/the-ritz-carlton/hotels/usa-and-canada/florida/miami-the-miami-beach-edition/guest-rooms/ED-MIAEB-07-new_RCMMBED_00024.png?$MedViewport100pct$","Serene Cove Resort & Spa",15,1,"mqy 6,2018","may 8,2018",1,1,"Canberra,Australia","USD 243");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://ritzcarlton-h.assetsadobe.com/is/image/content/dam/the-ritz-carlton/hotels/usa-and-canada/florida/miami-the-miami-beach-edition/guest-rooms/ED-MIAEB-07-new_RCMMBED_00024.png?$MedViewport100pct$","Serene Cove Resort & Spa",16,3,"may 14,2018","may 15, 2018",3,3,"Canberra,Australia","USD 243");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("http://www.bigyellowsuitcase.com.au/wp-content/uploads/2018/01/hotel-room.jpg", "Ancient Park Hotel", 12,2,"Apl 1,2018", "Apl 2, 2018", 1,1,"Adelaide, Australia","USD 248");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://q-ec.bstatic.com/images/hotel/max1280x900/370/37024558.jpg","Majestic Hotel",49,1,"june 2,2018","june 16, 2018",3,2,"brisbane, Australia","USD 153");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://r-ec.bstatic.com/images/hotel/max1280x900/378/37858797.jpg","Harborview Hotel",48,2,"july 23, 2018","july 29, 2018",4,1,"Melboune, Australia","USD 217");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://r-ec.bstatic.com/images/hotel/max1280x900/104/104972556.jpg","Revelation Resort",47,4,"may 3,2018","may 5,2018",4,1,"Hobart, Australia","USD 168");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112779353.jpg","Primal Pass Hotel", 46,4,"feb 17,2018","feb 19,2018",1,3,"Adelaide, Australia","USD");

INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://r-ec.bstatic.com/images/hotel/max1280x900/112/112782897.jpg","Amenity Hotel",45,3,"feb 15,2018","feb 21,2018",2,1,"Adelaide, Australia","USD 191");


INSERT INTO booking_pay (Image, hotel_name, RoomNumber, ReviewScore, Check_in_Date, Check_in_Out, Adults, kids, Location, Price) VALUE("https://fiestarancho.sclv.com/~/media/Images/Promotions/2017/January/FR-DeluxeKing.jpg?mw=460","Pleasant Echo Hotel",42, 5,"june 17,2018","june 17,2018",2,1,"Sydney, Australia","USD 183");

INSERT INTO reviews (hotel_name, rev_text) VALUES ("Ebony Castle Hotel", "The hotel was horrible, it was a terrible experience");
INSERT INTO reviews (hotel_name, rev_text) VALUES ("Silver Jewel Resort", "The hotel is amazing, it should be more expensive");