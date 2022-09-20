#pragma once

//
// Created by Joakim on 11/28/2020.
//
//================================================================
//                            <DESCRIPTION>
//This is out out manager which include all the documents related to managers like search, delete, and all other fuction
//===================================================================

#include"Listhead.h"

int insertManager(Listhead* cars);


int searchManager(Listhead* cars);
void primaryKeySearchManager(Listhead* cars);
void secondaryKeySearchManager(Listhead* cars);


int deleteManager(Listhead* cars);
void primaryDeleteManager(Listhead* cars);
void secondaryDeleteManager(Listhead* cars);


void displayManager(Car* C);
int exitManager();
void DisplayHeading();
void undoDelete(Listhead* cars);
void stats(Listhead* cars);