import 'package:flutter/material.dart';
import 'dart:ui';
import 'package:flutter_svg/flutter_svg.dart';
// import 'package:flutter_app/utils.dart';
import 'package:google_fonts/google_fonts.dart';
import 'auth.dart';
import 'package:intl/intl.dart';
import 'main.dart';
import 'dart:async';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';

class AccountPage extends StatelessWidget {
  final String userEmail = "admin@gmail.com";
  final FirebaseAuth _auth = FirebaseAuth.instance;
  // Controllers for email and password input fields
  final TextEditingController _emailController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();
  AccountPage({super.key});



  @override
  Widget build(BuildContext context) {
    
  Future<void> _register() async {
    try {
      // Attempt to create a new user with the provided email and password
      UserCredential userCredential = await _auth.createUserWithEmailAndPassword(
        email: _emailController.text.trim(),
        password: _passwordController.text.trim(),
      );

      // Successfully created a new user
      User? user = userCredential.user;
      if (user != null) {
        showDialog(
        context: context,
        builder: (context) {
          return AlertDialog(
            title: Text('Sucess!'),
            content: Text("successfully added new user"),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: Text('OK'),
              ),
            ],
          );
        },
      );

        // Navigate to the home page or display a success message
      }
    } on FirebaseAuthException catch (e) {
      // Handle errors from Firebase Authentication
      if (e.code == 'weak-password') {
        //print('The password provided is too weak.');
        showDialog(
        context: context,
        builder: (context) {
          return AlertDialog(
            title: Text('Error!'),
            content: Text(e.toString()),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: Text('OK'),
              ),
            ],
          );
        },
      );
      } else if (e.code == 'email-already-in-use') {
        // print('The account already exists for that email.');
        showDialog(
        context: context,
        builder: (context) {
          return AlertDialog(
            title: Text('Error!'),
            content: Text('email-already-in-use'),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: Text('OK'),
              ),
            ],
          );
        },
      );

      } else {
        showDialog(
        context: context,
        builder: (context) {
          return AlertDialog(
            title: Text('Error!'),
            content: Text(e.toString()),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: Text('OK'),
              ),
            ],
          );
        },
      );
      }
    } catch (e) {
     showDialog(
        context: context,
        builder: (context) {
          return AlertDialog(
            title: Text('Error!'),
            content: Text(e.toString()),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: Text('OK'),
              ),
            ],
          );
        },
      );
      //print(e);
      
    }
    //return false;
  }

    return Scaffold(
      appBar: AppBar(
        //titleSpacing: 50,
        //backgroundColor: Color.fromRGBO(255, 255, 255, 1),
        //toolbarHeight: 100,
        // title:  Text(
        //         'Authentication Page',
        //         style: GoogleFonts.getFont(
        //           'Inter',
        //           fontWeight: FontWeight.w700,
        //           fontSize: 27,
        //           height: 1,
        //           color: Color(0xFF000000),
                
        //         ),
        //         textAlign: TextAlign.center,
        //         overflow: TextOverflow.clip,
        //       ),
      ),
      body: 
      SingleChildScrollView(
      child: Center(
        
        child: Column(

          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'Welcome back!',
              style: GoogleFonts.getFont(
                                    'Inter',
                                    fontWeight: FontWeight.w400,
                                    fontSize: 30,
                                    height: 1,
                                    color: Color(0xFF000000),
                                   
                                  ),
            ),
            SizedBox(height: 16),
            Text(
              userEmail.split('@')[0],
              style: GoogleFonts.getFont(
                          'Inter',
                          fontWeight: FontWeight.w800,
                          fontSize: 27,
                          fontStyle: FontStyle.italic,
                          //height: 1,
                          color: Color.fromARGB(255, 89, 89, 89),
                        ),
            ),
            SizedBox(height: 100),
            Container(
              color: Color(0xFFE6E6E6),
              margin: EdgeInsets.all(20),
              
              // decoration: BoxDecoration(
              //   borderRadius: BorderRadius.circular(33),
              // ),
              child:  
                  Container(
              color: Color(0xFFE6E6E6),
              margin: EdgeInsets.all(20),
              child:  Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  'Add New User',
                  style: TextStyle(fontSize: 21),
                ),

                TextField(
                controller: _emailController,
                decoration: InputDecoration(labelText: "Email"),
                ),
                TextField(
                  controller: _passwordController,
                  decoration: InputDecoration(labelText: "Password"),
                  obscureText: true,
                ),
                SizedBox(height: 20),
                ElevatedButton(
                  onPressed: _register,
                  child: Text("Add New User"),
                ),

              
            ],

            ),
            ),
            ),
            SizedBox(height: 50),

            Positioned(
                bottom: 3,
                right: 3,
                child: ElevatedButton(
                  onPressed: () {
                    // Implement sign out functionality here
                    // use sign out function from firebase auth
                    _auth.signOut();
                    Navigator.pushReplacement(
                      context,
                      MaterialPageRoute(builder: (context) => AuthenticationPage()),
                    );
                  },
                  style: ButtonStyle(
                    backgroundColor: MaterialStateProperty.all<Color>(Color(0xFFE6E6E6)),
                  ),
                  child: Text("Sign Out"),
                ),
              ),  
      ],
      ),
      ),
      ),
    );

  }
}