import 'package:flutter/material.dart';
import 'dart:ui';
import 'package:flutter_svg/flutter_svg.dart';
// import 'package:flutter_app/utils.dart';
import 'package:google_fonts/google_fonts.dart';
import 'auth.dart';
import 'package:intl/intl.dart';
import 'main.dart';
import 'dart:async';
import 'dart:convert';
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_database/firebase_database.dart';
import 'account.dart';

class Dashboard extends StatefulWidget {
  @override
  _DashboardState createState() => _DashboardState();
}

class _DashboardState extends State<Dashboard> {
  
  String _imageBase64 = '';

  @override
  void initState() {
    super.initState();
    _getImageFromFirebase();

  }


  final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref();

  final DatabaseReference _databaseReference2 = FirebaseDatabase.instance.ref('chunk');
  
  void _getImageFromFirebase() {
    
  //final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref('chunk0');
  
    _databaseReference2.onValue.listen((DatabaseEvent event) {
      final imageBase64 = event.snapshot.value as String?;
      if (imageBase64 != null) {
        setState(() {
          _imageBase64 = imageBase64;
        });
      }
    });
  }
  
  @override
  Widget build(BuildContext context) {
    return 
    Container(
      decoration: BoxDecoration(
        color: Color(0xFFFFFFFF),
      ),
      child: Container(
        child: Stack(
          clipBehavior: Clip.antiAlias,
          children: [
            SizedBox(
              width: double.infinity,
              child: Column(
                mainAxisAlignment: MainAxisAlignment.start,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Container(
                    margin: EdgeInsets.fromLTRB(20, 50, 20, 48),
                    child: Align(
                      alignment: Alignment.topRight,
                      child: SizedBox(
                        width: 256.6,
                        height: 50,
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Container(
                              margin: EdgeInsets.fromLTRB(0, 10, 15, 14),
                              child: SizedBox(
                                child: Text(
                                  'Dashboard',
                                  style: GoogleFonts.getFont(
                                    'Inter',
                                    fontWeight: FontWeight.w700,
                                    fontSize: 30,
                                    height: 1,
                                    color: Color(0xFF000000),
                                   
                                  ),
                                  overflow: TextOverflow.clip,
                                ),
                              ),
                            ),
                            GestureDetector(
                              onTap: () {
                                // Your onPress function here
                               Navigator.push(context, MaterialPageRoute(builder: (context) => AccountPage()));
             
                              },
                              child:
                              Container(
                              margin: EdgeInsets.fromLTRB(0, 0, 0, 0),
                              child: Container(
                                decoration: BoxDecoration(
                                  borderRadius: BorderRadius.circular(9999),
                                  image: DecorationImage(
                                    fit: BoxFit.cover,
                                    image: AssetImage(
                                      'assets/images/shape.png',
                                    ),
                                  ),
                                ),
                                child: Container(
                                  width: 40,
                                  height: 40,
                                  child: Container(
                                    decoration: BoxDecoration(
                                      borderRadius: BorderRadius.circular(40),
                                      image: DecorationImage(
                                        fit: BoxFit.cover,
                                        image: AssetImage(
                                          'assets/images/image_4.png',
                                        ),
                                      ),
                                    ),
                                    child: Container(
                                      width: 40,
                                      height: 40,
                                    ),
                                  ),
                                ),
                              ),
                            ),
                            ),
                          ],
                        ),
                      ),
                    ),
                  ),
                  
                  Container(
                    //margin: EdgeInsets.fromLTRB(20, 10, 20, 10),
                    child: Container(
                      decoration: BoxDecoration(
                        color: Color(0xFFE6E6E6),
                        borderRadius: BorderRadius.circular(20),
                      ),
                      child: Container(
                        width: 300,
                        height: 300,
                        padding: EdgeInsets.fromLTRB(15, 8, 15, 8),
                        child: Transform.rotate(
                        angle: -1.57, // Adjust this value to rotate the image (e.g., 0.5 for ~28.6 degrees)
                        child: Container(
                     
                          decoration: BoxDecoration(
                          borderRadius: BorderRadius.circular(20),
                            
                            image: DecorationImage(
                              fit: BoxFit.fill,
                              image: MemoryImage(
                                  base64Decode(_imageBase64),
                                    //"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"),
                                  //int x = Base64Class::decode();
                                
                                )//: CircularProgressIndicator(),
                      
                              ),
                          )
                            ),       
                      ),
                    ),
                  ),
                  ),
                  Container(
                    margin: EdgeInsets.fromLTRB(4, 20, 0, 20),
                    
                    child: FittedBox(
                      fit: BoxFit.scaleDown,
                      child: Text(
                        'Live Camera',
                        style: GoogleFonts.getFont(
                          'Inter',
                          fontWeight: FontWeight.w400,
                          fontSize: 27,
                          //height: 1,
                          color: Color(0xFF000000),
                        ),
                      ),
                    ),
                  ),
                  GestureDetector(
                    onTap: () {
                      // Your onPress function here
                       _databaseReference.child('lock').set(100);
                      // get current epoch time
                      //_databaseReference.child('time').set();
                      // wait for 5 seconds
                      Future.delayed(const Duration(seconds: time_for_lock), () {
                        _databaseReference.child('lock').set(0);
                      });

                      // show notification from above
                      showDialog(
                      context: context,
                      builder: (BuildContext context) {
                        return AlertDialog(
                          title: Text('Unlocking...'),
                          content: Text('Your door is being unlocked remotely!'),
                          actions: <Widget>[
                            TextButton(
                              child: Text('OK'),
                              onPressed: () {
                                Navigator.of(context).pop();
                              },
                            ),
                          ],
                        );

                      }
                      );                      
                      // final snackBar = SnackBar(content: Text('Unlocking Door Remotely!'),  duration: Duration(seconds: 5),);
                      // ScaffoldMessenger.of(context).showSnackBar(snackBar);

                    },
                    child:
                    Container(
                    margin: EdgeInsets.fromLTRB(0, 10, 0, 11),
                    child: Container(
                      decoration: BoxDecoration(
                        color: Color(0xFFD9D9D9),
                        borderRadius: BorderRadius.circular(41.5),
                      ),
                      child: Container(
                        width: 83,
                        height: 83,
                        padding: EdgeInsets.fromLTRB(1, 22, 0, 21),
                        child: Container(
                          width: 48,
                          height: 48,
                          child: SizedBox(
                            width: 36,
                            height: 40,
                            child: Image.asset(
                              'assets/images/icon_12_x2.png',
                            ),
                          ),
                        ),
                      ),
                    ),
                  ),
                  ),
                  Container(
                    margin: EdgeInsets.fromLTRB(0, 0, 0, 55),
                    child: Text(
                      'Unlock Door',
                      style: GoogleFonts.getFont(
                        'Inter',
                        fontWeight: FontWeight.w400,
                        fontSize: 25,
                        height: 1.2,
                        color: Color(0xFF000000),
                      ),
                    ),
                  ),
                  GestureDetector(
                    onTap: () {
                      // Your onPress function here
                      Navigator.push(context, MaterialPageRoute(builder: (context) => AddPasswordPage(title: "Add Password")));
                    },
                    child:
                    
                  Container(
                    margin: EdgeInsets.fromLTRB(20, 0, 20, 62),
                    child:
                    Container(
                      decoration: BoxDecoration(
                        color: Color(0x80D9D9D9),
                        borderRadius: BorderRadius.circular(50),
                      ),
                      child: Row(children: [                    
                          Container(
                          padding: EdgeInsets.fromLTRB(15, 12.5, 0, 13.5),
                          child:
                          Image.asset(
                            'assets/images/settings-svgrepo-com.png', // Replace with your image path
                            width: 24, // Adjust the width as needed
                            height: 24, // Adjust the height as needed
                          ),
                        ),
                          

                        Container(
                        width: 300,
                        padding: EdgeInsets.fromLTRB(40, 12.5, 0, 13.5),
                        child: Text(
                          'Manage Passwords',
                          style: GoogleFonts.getFont(
                            'Inter',
                            fontWeight: FontWeight.w400,
                            fontSize: 22,
                            height: 1.4,
                            color: Color(0xFF000000),
                          ),
                        ),
                      ),
                      ],)
                    ),
                  
                  
                  ),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}












// import 'package:flutter/material.dart';
// import 'dart:ui';
// import 'package:flutter_svg/flutter_svg.dart';
// // import 'package:flutter_app/utils.dart';
// import 'package:google_fonts/google_fonts.dart';

// class Iphone1415Pro4 extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return 
//     Container(
//       decoration: BoxDecoration(
//         color: Color(0xFFFFFFFF),
//       ),
//       child: Stack(
//         children: [
//           SizedBox(
//             width: 390,
//             child: Column(
//               mainAxisAlignment: MainAxisAlignment.start,
//               crossAxisAlignment: CrossAxisAlignment.start,
//               children: [

//                 Container(
//                   margin: EdgeInsets.fromLTRB(17.6, 0, 0, 0),
//                   child: Container(
//                     decoration: BoxDecoration(
//                       color: Color(0xFFFFFFFF),
//                     ),
//                     child: Container(
//                       padding: EdgeInsets.fromLTRB(0, 18.3, 32.2, 0),
//                       child: Row(
//                         mainAxisAlignment: MainAxisAlignment.spaceBetween,
//                         crossAxisAlignment: CrossAxisAlignment.start,
//                         children: [
//                           Container(
//                             margin: EdgeInsets.fromLTRB(0, 4.7, 0, 0),
//                             child: SizedBox(
//                               width: 140.5,
//                               child: Row(
//                                 mainAxisAlignment: MainAxisAlignment.start,
//                                 crossAxisAlignment: CrossAxisAlignment.start,
//                                 children: [
//                                   Container(
//                                     margin: EdgeInsets.fromLTRB(0, 0.5, 7.5, 0.2),
//                                     child: SizedBox(
//                                       width: 19.2,
//                                       height: 12.2,
//                                       child: SvgPicture.asset(
//                                         'assets/vectors/cellular_connection_3_x2.svg',
//                                       ),
//                                     ),
//                                   ),
//                                   Container(
//                                     margin: EdgeInsets.fromLTRB(0, 0.6, 7.2, 0),
//                                     child: SizedBox(
//                                       width: 17.1,
//                                       height: 12.3,
//                                       child: SvgPicture.asset(
//                                         'assets/vectors/wifi_4_x2.svg',
//                                       ),
//                                     ),
//                                   ),
//                                   SizedBox(
//                                     width: 27.3,
//                                     height: 13,
//                                     child: SvgPicture.asset(
//                                       'assets/vectors/battery_3_x2.svg',
//                                     ),
//                                   ),
//                                 ],
//                               ),
//                             ),
//                           ),
//                         ],
//                       ),
//                     ),
//                   ),
//                 ),
//                 Container(
//                   margin: EdgeInsets.fromLTRB(30.4, 20, 30.4, 0),
//                   child: Align(
//                     alignment: Alignment.topLeft,
//                     child: Row(
//                       mainAxisAlignment: MainAxisAlignment.start,
//                       crossAxisAlignment: CrossAxisAlignment.start,
//                       children: [
//                         Container(
//                           margin: EdgeInsets.fromLTRB(0, 30,0, 20),
//                           width: 35,
//                           height: 30,
//                           child: SizedBox(
//                             width: 23.3,
//                             height: 20,
//                             child: SvgPicture.asset(
//                               'assets/vectors/icon_5_x2.svg',
//                             ),
//                           ),
//                         ),
//                         Text(
//                           'Manage Passwords',
//                           style: GoogleFonts.getFont(
//                             'Inter',
//                             fontWeight: FontWeight.w700,
//                             fontSize: 30,
//                             height: 1,
//                             color: Color(0xFF000000),
//                           ),
//                         ),
//                       ],
//                     ),
//                   ),
//                 ),
//                 Container(
//                   margin: EdgeInsets.fromLTRB(33.6, 5, 16, 4),
//                   child: Column(
//                     mainAxisAlignment: MainAxisAlignment.start,
//                     crossAxisAlignment: CrossAxisAlignment.start,
//                     children: [
//                       Container(
//                         margin: EdgeInsets.fromLTRB(16, 0, 16, 7),
//                         child: Align(
//                           alignment: Alignment.topLeft,
//                           child: Container(
//                             child: Text(
//                               'PASSWORDS',
//                               style: GoogleFonts.getFont(
//                                 'Inter',
//                                 fontWeight: FontWeight.w400,
//                                 fontSize: 13,
//                                 height: 1.2,
//                                 color: Color(0x993C3C43),
//                               ),
//                             ),
//                           ),
//                         ),
//                       ),
//                       Container(
//                         margin: EdgeInsets.fromLTRB(0, 0, 0, 45),
//                         child: Container(
//                           decoration: BoxDecoration(
//                             color: Color(0xFFFFFFFF),
//                             borderRadius: BorderRadius.circular(10),
//                           ),
//                           child: Container(
//                             padding: EdgeInsets.fromLTRB(16, 0, 0, 0),
//                             child: Column(
//                               mainAxisAlignment: MainAxisAlignment.start,
//                               crossAxisAlignment: CrossAxisAlignment.start,
//                               children: [
//                                 Container(
//                                   child: Container(
//                                     width: double.infinity,
//                                     padding: EdgeInsets.fromLTRB(0, 11, 0, 11),
//                                     decoration: BoxDecoration(
//                                       // border: Border(
//                                       //     color: Color(0x57545456),
//                                       //     width: 0.3,
//                                       // ),
//                                     ),
//                                     child: Text(
//                                       '2368',
//                                       style: GoogleFonts.getFont(
//                                         'Inter',
//                                         fontWeight: FontWeight.w400,
//                                         fontSize: 17,
//                                         height: 1.3,
//                                         letterSpacing: -0.4,
//                                         color: Color(0xFF000000),
//                                       ),
//                                     ),
//                                   ),
//                                 ),
//                                 Container(
//                                   child: Container(
//                                     width: double.infinity,
//                                     decoration: BoxDecoration(
//                                       // border: Border(
                                        
//                                       //     color: Color(0x57545456),
//                                       //     width: 0.3,
                                        
//                                       // ),
//                                     ),
//                                     child: Container(
//                                       padding: EdgeInsets.fromLTRB(0, 11, 18.9, 11),
//                                       child: Row(
//                                         mainAxisAlignment: MainAxisAlignment.spaceBetween,
//                                         crossAxisAlignment: CrossAxisAlignment.start,
//                                         children: [
//                                           Container(
//                                             child: Text(
//                                               '976A',
//                                               style: GoogleFonts.getFont(
//                                                 'Inter',
//                                                 fontWeight: FontWeight.w400,
//                                                 fontSize: 17,
//                                                 height: 1.3,
//                                                 letterSpacing: -0.4,
//                                                 color: Color(0xFF000000),
//                                               ),
//                                             ),
//                                           ),
//                                           Container(
//                                             child: Text(
//                                               '􀅴',
//                                               style: GoogleFonts.getFont(
//                                                 'Inter',
//                                                 fontWeight: FontWeight.w400,
//                                                 fontSize: 17,
//                                                 height: 1.3,
//                                                 color: Color(0xFF007AFF),
//                                               ),
//                                             ),
//                                           ),
//                                         ],
//                                       ),
//                                     ),
//                                   ),
//                                 ),
//                                 Container(
//                                   child: Container(
//                                     width: double.infinity,
//                                     decoration: BoxDecoration(
//                                       // border: Border(
                                        
//                                       //     color: Color(0x57545456),
//                                       //     width: 0.3,
                                        
//                                       // ),
//                                     ),
//                                     child: Container(
//                                       padding: EdgeInsets.fromLTRB(0, 11, 18.9, 11),
//                                       child: Row(
//                                         mainAxisAlignment: MainAxisAlignment.spaceBetween,
//                                         crossAxisAlignment: CrossAxisAlignment.start,
//                                         children: [
//                                           Container(
//                                             child: Text(
//                                               '1606',
//                                               style: GoogleFonts.getFont(
//                                                 'Inter',
//                                                 fontWeight: FontWeight.w400,
//                                                 fontSize: 17,
//                                                 height: 1.3,
//                                                 letterSpacing: -0.4,
//                                                 color: Color(0xFF000000),
//                                               ),
//                                             ),
//                                           ),
//                                           Container(
//                                             child: Text(
//                                               '􀋂',
//                                               style: GoogleFonts.getFont(
//                                                 'Inter',
//                                                 fontWeight: FontWeight.w400,
//                                                 fontSize: 17,
//                                                 height: 1.3,
//                                                 color: Color(0xFF007AFF),
//                                               ),
//                                             ),
//                                           ),
//                                         ],
//                                       ),
//                                     ),
//                                   ),
//                                 ),
//                                 Container(
//                                   child: Container(
//                                     width: double.infinity,
//                                     decoration: BoxDecoration(
//                                       // border: Border(
                                        
//                                       //     color: Color(0x57545456),
//                                       //     width: 0.3,
                                        
//                                       // ),
//                                     ),
//                                     child: Container(
//                                       padding: EdgeInsets.fromLTRB(0, 11, 15.9, 11),
//                                       child: Row(
//                                         mainAxisAlignment: MainAxisAlignment.spaceBetween,
//                                         crossAxisAlignment: CrossAxisAlignment.start,
//                                         children: [
//                                           Container(
//                                             child: Text(
//                                               'AC23',
//                                               style: GoogleFonts.getFont(
//                                                 'Inter',
//                                                 fontWeight: FontWeight.w400,
//                                                 fontSize: 17,
//                                                 height: 1.3,
//                                                 letterSpacing: -0.4,
//                                                 color: Color(0xFF000000),
//                                               ),
//                                             ),
//                                           ),
//                                           Container(
//                                             child: Text(
//                                               '􀆅',
//                                               style: GoogleFonts.getFont(
//                                                 'Inter',
//                                                 fontWeight: FontWeight.w600,
//                                                 fontSize: 17,
//                                                 height: 1.3,
//                                                 color: Color(0xFF007AFF),
//                                               ),
//                                             ),
//                                           ),
//                                         ],
//                                       ),
//                                     ),
//                                   ),
//                                 ),
//                               ],
//                             ),
//                           ),
//                         ),
//                       ),
//                       Container(
//                         margin: EdgeInsets.fromLTRB(16, 0, 16, 0),
//                         child: Align(
//                           alignment: Alignment.topLeft,
//                           child: Container(
//                             child: Text(
//                               'NEW PASSWORD',
//                               style: GoogleFonts.getFont(
//                                 'Inter',
//                                 fontWeight: FontWeight.w400,
//                                 fontSize: 13,
//                                 height: 1.2,
//                                 color: Color(0x993C3C43),
//                               ),
//                             ),
//                           ),
//                         ),
//                       ),
//                       Container(
//                         margin: EdgeInsets.fromLTRB(0, 0, 0, 2),
//                         child: Container(
//                           decoration: BoxDecoration(
//                             color: Color(0xFFFFFFFF),
//                             borderRadius: BorderRadius.circular(10),
//                           ),
//                           child: Column(
//                             mainAxisAlignment: MainAxisAlignment.start,
//                             crossAxisAlignment: CrossAxisAlignment.start,
//                             children: [
//                               Container(
//                                 padding: EdgeInsets.fromLTRB(16, 0, 0, 0),
//                                 decoration: BoxDecoration(
//                                   border: Border.all(color: Color(0xFF000000)),
//                                 ),
//                                 child: Container(
//                                   width: double.infinity,
//                                   padding: EdgeInsets.fromLTRB(0, 11, 0, 11),
//                                   decoration: BoxDecoration(
//                                     // border: Border(
                                      
//                                     //     color: Color(0x57545456),
//                                     //     width: 0.3,
                                      
//                                     // ),
//                                   ),
//                                   child: Text(
//                                     'Type new password',
//                                     style: GoogleFonts.getFont(
//                                       'Inter',
//                                       fontWeight: FontWeight.w400,
//                                       fontSize: 17,
//                                       height: 1.3,
//                                       letterSpacing: -0.4,
//                                       color: Color(0x8C808080),
//                                     ),
//                                   ),
//                                 ),
//                               ),
//                               Container(
//                                 margin: EdgeInsets.fromLTRB(16, 0, 0, 0),
//                                 child: Container(
//                                   width: double.infinity,
//                                   decoration: BoxDecoration(
//                                     // border: Border(
                                      
//                                     //     color: Color(0x57545456),
//                                     //     width: 0.3,
                                      
//                                     // ),
//                                   ),
//                                   child: Container(
//                                     padding: EdgeInsets.fromLTRB(0, 6.5, 16, 6.5),
//                                     child: Row(
//                                       mainAxisAlignment: MainAxisAlignment.spaceBetween,
//                                       crossAxisAlignment: CrossAxisAlignment.start,
//                                       children: [
//                                         Container(
//                                           margin: EdgeInsets.fromLTRB(0, 4.5, 0, 4.5),
//                                           child: Text(
//                                             'Temporary',
//                                             style: GoogleFonts.getFont(
//                                               'Inter',
//                                               fontWeight: FontWeight.w400,
//                                               fontSize: 17,
//                                               height: 1.3,
//                                               letterSpacing: -0.4,
//                                               color: Color(0xFF000000),
//                                             ),
//                                           ),
//                                         ),
//                                         Container(
//                                           width: 67,
//                                           height: 44,
//                                           child: Container(
//                                             decoration: BoxDecoration(
//                                               color: Color(0xFF34C759),
//                                               borderRadius: BorderRadius.circular(100),
//                                             ),
//                                             child: Container(
//                                               width: 51,
//                                               height: 31,
//                                               padding: EdgeInsets.fromLTRB(2, 2, 2, 2),
//                                               child: Container(
//                                                 decoration: BoxDecoration(
//                                                   borderRadius: BorderRadius.circular(100),
//                                                   color: Color(0xFFFFFFFF),
//                                                   boxShadow: [
//                                                     BoxShadow(
//                                                       color: Color(0x0F000000),
//                                                       offset: Offset(0, 3),
//                                                       blurRadius: 0.5,
//                                                     ),
//                                                     BoxShadow(
//                                                       color: Color(0x26000000),
//                                                       offset: Offset(0, 3),
//                                                       blurRadius: 4,
//                                                     ),
//                                                     BoxShadow(
//                                                       color: Color(0x0A000000),
//                                                       offset: Offset(0, 0),
//                                                       blurRadius: 0,
//                                                     ),
//                                                   ],
//                                                 ),
//                                                 child: Container(
//                                                   width: 27,
//                                                   height: 27,
//                                                 ),
//                                               ),
//                                             ),
//                                           ),
//                                         ),
//                                       ],
//                                     ),
//                                   ),
//                                 ),
//                               ),
//                             ],
//                           ),
//                         ),
//                       ),
//                       Container(
//                         margin: EdgeInsets.fromLTRB(0, 0, 0, 32),
//                         child: Align(
//                           alignment: Alignment.topCenter,
//                           child: Row(
//                             mainAxisAlignment: MainAxisAlignment.start,
//                             crossAxisAlignment: CrossAxisAlignment.start,
//                             children: [
//                               Container(
//                                 margin: EdgeInsets.fromLTRB(0, 0, 6, 0),
//                                 child: Container(
//                                   decoration: BoxDecoration(
//                                     color: Color(0x1F787880),
//                                     borderRadius: BorderRadius.circular(6),
//                                   ),
//                                   child: Container(
//                                     padding: EdgeInsets.fromLTRB(15.4, 6, 15.4, 6),
//                                     child: Row(
//                                       mainAxisAlignment: MainAxisAlignment.start,
//                                       crossAxisAlignment: CrossAxisAlignment.start,
//                                       children: [
//                                         Container(
//                                           margin: EdgeInsets.fromLTRB(0, 0, 13.8, 0),
//                                           child: Text(
//                                             'Jun 10,',
//                                             style: GoogleFonts.getFont(
//                                               'Roboto Condensed',
//                                               fontWeight: FontWeight.w400,
//                                               fontSize: 17,
//                                               height: 1.3,
//                                               letterSpacing: -0.4,
//                                               color: Color(0xFF007AFF),
//                                             ),
//                                           ),
//                                         ),
//                                         Text(
//                                           '2024',
//                                           style: GoogleFonts.getFont(
//                                             'Roboto Condensed',
//                                             fontWeight: FontWeight.w400,
//                                             fontSize: 17,
//                                             height: 1.3,
//                                             letterSpacing: -0.4,
//                                             color: Color(0xFF007AFF),
//                                           ),
//                                         ),
//                                       ],
//                                     ),
//                                   ),
//                                 ),
//                               ),
//                               Container(
//                                 decoration: BoxDecoration(
//                                   color: Color(0x1F787880),
//                                   borderRadius: BorderRadius.circular(6),
//                                 ),
//                                 child: Container(
//                                   padding: EdgeInsets.fromLTRB(16.4, 6, 16.4, 6),
//                                   child: Text(
//                                     '9:41 AM',
//                                     style: GoogleFonts.getFont(
//                                       'Roboto Condensed',
//                                       fontWeight: FontWeight.w400,
//                                       fontSize: 17,
//                                       height: 1.3,
//                                       letterSpacing: -0.4,
//                                       color: Color(0xFF007AFF),
//                                     ),
//                                   ),
//                                 ),
//                               ),
//                             ],
//                           ),
//                         ),
//                       ),
//                       Container(
//                         decoration: BoxDecoration(
//                           color: Color(0xFFFFFFFF),
//                           borderRadius: BorderRadius.circular(10),
//                         ),
//                         child: Container(
//                           padding: EdgeInsets.fromLTRB(16, 0, 0, 0),
//                           child: Container(
//                             width: double.infinity,
//                             padding: EdgeInsets.fromLTRB(0, 11, 16, 11),
//                             decoration: BoxDecoration(
//                               // border: Border(
//                               //   bottom: (
//                               //     color: Color(0x57545456),
//                               //     width: 0.3,
//                               //   ),
//                               // ),
//                             ),
//                             child: Text(
//                               'Add Password',
//                               style: GoogleFonts.getFont(
//                                 'Inter',
//                                 fontWeight: FontWeight.w400,
//                                 fontSize: 17,
//                                 height: 1.3,
//                                 letterSpacing: -0.4,
//                                 color: Color(0xFF007AFF),
//                               ),
//                             ),
//                           ),
//                         ),
//                       ),
//                     ],
//                   ),
//                 ),
//               ],
//             ),
//           ),
//           Positioned(
//             right: -40,
//             bottom: -40,
//             child: Container(
//               width: 393,
//               height: 1071,
//               child: Container(
//                 decoration: BoxDecoration(
//                   image: DecorationImage(
//                     fit: BoxFit.cover,
//                     image: AssetImage(
//                       'assets/images/iphone_15_pro_black_titanium_portrait.png',
//                     ),
//                   ),
//                 ),
//                 child: Container(
//                   width: 473,
//                   height: 932,
//                 ),
//               ),
//             ),
//           ),
//         ],
//       ),
//     );
//   }
// }