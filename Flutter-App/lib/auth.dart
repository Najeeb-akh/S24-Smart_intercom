import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:smartdoorbell/Dashboard.dart';
import 'main.dart';
import 'package:google_fonts/google_fonts.dart';

class AuthenticationPage extends StatefulWidget {
  @override
  _AuthenticationPageState createState() => _AuthenticationPageState();
}

class _AuthenticationPageState extends State<AuthenticationPage> {
  final FirebaseAuth _auth = FirebaseAuth.instance;
  final TextEditingController _usernameController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();
  final FocusNode _usernameFocusNode = FocusNode();
  final FocusNode _passwordFocusNode = FocusNode();
  bool _isLogoCollapsed = false;

  
  @override
  void initState() {
    super.initState();
    _usernameFocusNode.addListener(_onFocusChange);
    _passwordFocusNode.addListener(_onFocusChange);
  }

  void _onFocusChange() {
    setState(() {
      _isLogoCollapsed = _usernameFocusNode.hasFocus || _passwordFocusNode.hasFocus;
    });
  }

  @override
  void dispose() {
    _usernameFocusNode.dispose();
    _passwordFocusNode.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      
      
      backgroundColor: Color.fromRGBO(255, 255, 255, 1),
      appBar: AppBar(
        automaticallyImplyLeading: false,
        titleSpacing: 50,
        backgroundColor: Color.fromRGBO(255, 255, 255, 1),
        toolbarHeight: 100,
        title:  Text(
                'Authentication Page',
                style: GoogleFonts.getFont(
                  'Inter',
                  fontWeight: FontWeight.w700,
                  fontSize: 27,
                  height: 1,
                  color: Color(0xFF000000),
                
                ),
                textAlign: TextAlign.center,
                overflow: TextOverflow.clip,
              ),
      ),
      body: 
     SingleChildScrollView(
      child: Padding(
        padding: EdgeInsets.fromLTRB(20,0,20,0),
        child: Column(
          
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
           Container(
                    height: 450,
                    padding: EdgeInsets.fromLTRB(7, 4, 8, 8),
                    child: Container(
                      decoration: BoxDecoration(
                        image: DecorationImage(
                          fit: BoxFit.cover,
                          image: AssetImage(
                            'assets/images/logo.png',
                          ),
                        ),
                      ),
                      
                    ),
            ),
        
            TextField(
              controller: _usernameController,
              decoration: InputDecoration(
                labelText: 'Username',
              ),
            ),
            SizedBox(height: 16.0),
            TextField(
              controller: _passwordController,
              decoration: InputDecoration(
                labelText: 'Password',
              ),
              obscureText: true,
            ),
            SizedBox(height: 40.0),
            
            Container(
              width: 170,
              child: FloatingActionButton(
              // change size of the button
              
              mini: false,

              onPressed: () {
                _signIn();
              },
              tooltip: 'Sign In',
              backgroundColor: Color.fromRGBO(208, 210, 210, 1),
              child: Container(
                
                // add to the container a text alongside the icon
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    const Icon(Icons.login),
                    const SizedBox(width: 8.0),
                    const Text('Sign In'),
                  ],
                ),

                ),
            ),
            ),

            
          ],
        ),
      ),
     ),
    );
  }

  Future<void> _signIn() async {
    try {
      UserCredential userCredential = await _auth.signInWithEmailAndPassword(
        email: _usernameController.text,
        password: _passwordController.text,
      );
      // Handle successful sign in here
      // go to home page from the main.dart file
      //Navigator.of(context).pushReplacementNamed('/home');
      // navigate to MyHomePage from the main.dart file
      print("User");
      Navigator.of(context).pushReplacement(MaterialPageRoute(builder: (context) => Dashboard()));
    } catch (e) {
      // Handle sign in error here
      // prompt the user by showing a popup message on the screen
      showDialog(
        context: context,
        builder: (context) {
          return AlertDialog(
            title: Text('Error'),
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
  }
}