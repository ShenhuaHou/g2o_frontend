//#line 2 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the robot_eye_driver package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __robot_eye_driver__ROBOTEYEPARAMETERSCONFIG_H__
#define __robot_eye_driver__ROBOTEYEPARAMETERSCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace robot_eye_driver
{
  class RobotEyeParametersConfigStatics;
  
  class RobotEyeParametersConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(RobotEyeParametersConfig &config, const RobotEyeParametersConfig &max, const RobotEyeParametersConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const RobotEyeParametersConfig &config1, const RobotEyeParametersConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, RobotEyeParametersConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const RobotEyeParametersConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, RobotEyeParametersConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const RobotEyeParametersConfig &config) const = 0;
      virtual void getValue(const RobotEyeParametersConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T RobotEyeParametersConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (RobotEyeParametersConfig::* field);

      virtual void clamp(RobotEyeParametersConfig &config, const RobotEyeParametersConfig &max, const RobotEyeParametersConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const RobotEyeParametersConfig &config1, const RobotEyeParametersConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, RobotEyeParametersConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const RobotEyeParametersConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, RobotEyeParametersConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const RobotEyeParametersConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const RobotEyeParametersConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, RobotEyeParametersConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); i++)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;
        
        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++) 
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }
      
      virtual void updateParams(boost::any &cfg, RobotEyeParametersConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++) 
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<RobotEyeParametersConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(RobotEyeParametersConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = params.begin(); i != params.end(); i++)
      {
        boost::any val;
        (*i)->getValue(config, val);

        if("az_rate"==(*i)->name){az_rate = boost::any_cast<double>(val);}
        if("n_lines"==(*i)->name){n_lines = boost::any_cast<int>(val);}
        if("averaging"==(*i)->name){averaging = boost::any_cast<int>(val);}
        if("laser_freq"==(*i)->name){laser_freq = boost::any_cast<int>(val);}
        if("intensity"==(*i)->name){intensity = boost::any_cast<bool>(val);}
        if("node_state"==(*i)->name){node_state = boost::any_cast<int>(val);}
      }
    }

    double az_rate;
int n_lines;
int averaging;
int laser_freq;
bool intensity;
int node_state;

    bool state;
    std::string name;

    
}groups;



//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      double az_rate;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      int n_lines;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      int averaging;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      int laser_freq;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      bool intensity;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      int node_state;
//#line 255 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("RobotEyeParametersConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const RobotEyeParametersConfig &__max__ = __getMax__();
      const RobotEyeParametersConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const RobotEyeParametersConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const RobotEyeParametersConfig &__getDefault__();
    static const RobotEyeParametersConfig &__getMax__();
    static const RobotEyeParametersConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const RobotEyeParametersConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void RobotEyeParametersConfig::ParamDescription<std::string>::clamp(RobotEyeParametersConfig &config, const RobotEyeParametersConfig &max, const RobotEyeParametersConfig &min) const
  {
    return;
  }

  class RobotEyeParametersConfigStatics
  {
    friend class RobotEyeParametersConfig;
    
    RobotEyeParametersConfigStatics()
    {
RobotEyeParametersConfig::GroupDescription<RobotEyeParametersConfig::DEFAULT, RobotEyeParametersConfig> Default("Default", "", 0, 0, true, &RobotEyeParametersConfig::groups);
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __min__.az_rate = 1.0;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __max__.az_rate = 15.0;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __default__.az_rate = 10.0;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<double>("az_rate", "double", 0, "Number of rounds per second [max:15(5400 degrees/sec)]", "", &RobotEyeParametersConfig::az_rate)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<double>("az_rate", "double", 0, "Number of rounds per second [max:15(5400 degrees/sec)]", "", &RobotEyeParametersConfig::az_rate)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __min__.n_lines = -2147483648;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __max__.n_lines = 2147483647;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __default__.n_lines = 100;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("n_lines", "int", 0, "Number of horizontal lines (vertical resolution) [min:az_rate]", "", &RobotEyeParametersConfig::n_lines)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("n_lines", "int", 0, "Number of horizontal lines (vertical resolution) [min:az_rate]", "", &RobotEyeParametersConfig::n_lines)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __min__.averaging = 1;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __max__.averaging = 5;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __default__.averaging = 1;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("averaging", "int", 0, "'averaging' value range:[1,5]", "", &RobotEyeParametersConfig::averaging)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("averaging", "int", 0, "'averaging' value range:[1,5]", "", &RobotEyeParametersConfig::averaging)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __min__.laser_freq = 1;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __max__.laser_freq = 30000;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __default__.laser_freq = 10000;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("laser_freq", "int", 0, "Measurement frequency [range:[1, 30000]]", "", &RobotEyeParametersConfig::laser_freq)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("laser_freq", "int", 0, "Measurement frequency [range:[1, 30000]]", "", &RobotEyeParametersConfig::laser_freq)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __min__.intensity = 0;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __max__.intensity = 1;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __default__.intensity = 0;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<bool>("intensity", "bool", 0, "Enable the streaming of intensity values [can be 'on' only if laser_freq <= 10000]", "", &RobotEyeParametersConfig::intensity)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<bool>("intensity", "bool", 0, "Enable the streaming of intensity values [can be 'on' only if laser_freq <= 10000]", "", &RobotEyeParametersConfig::intensity)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __min__.node_state = 0;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __max__.node_state = 2;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __default__.node_state = 1;
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.abstract_parameters.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("node_state", "int", 0, "A state parameter which is edited via an enum", "{'enum_description': 'An enum to set the state od the publisher node', 'enum': [{'srcline': 17, 'description': 'The state is STOP', 'srcfile': '../cfg/RobotEyeParameters.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'stop'}, {'srcline': 18, 'description': 'The state is RUN', 'srcfile': '../cfg/RobotEyeParameters.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'run'}, {'srcline': 19, 'description': 'The state is PAUSE', 'srcfile': '../cfg/RobotEyeParameters.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'pause'}]}", &RobotEyeParametersConfig::node_state)));
//#line 259 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __param_descriptions__.push_back(RobotEyeParametersConfig::AbstractParamDescriptionConstPtr(new RobotEyeParametersConfig::ParamDescription<int>("node_state", "int", 0, "A state parameter which is edited via an enum", "{'enum_description': 'An enum to set the state od the publisher node', 'enum': [{'srcline': 17, 'description': 'The state is STOP', 'srcfile': '../cfg/RobotEyeParameters.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'stop'}, {'srcline': 18, 'description': 'The state is RUN', 'srcfile': '../cfg/RobotEyeParameters.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'run'}, {'srcline': 19, 'description': 'The state is PAUSE', 'srcfile': '../cfg/RobotEyeParameters.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'pause'}]}", &RobotEyeParametersConfig::node_state)));
//#line 233 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      Default.convertParams();
//#line 233 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator.py"
      __group_descriptions__.push_back(RobotEyeParametersConfig::AbstractGroupDescriptionConstPtr(new RobotEyeParametersConfig::GroupDescription<RobotEyeParametersConfig::DEFAULT, RobotEyeParametersConfig>(Default)));
//#line 390 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h.template"
    
      for (std::vector<RobotEyeParametersConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<RobotEyeParametersConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<RobotEyeParametersConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    RobotEyeParametersConfig __max__;
    RobotEyeParametersConfig __min__;
    RobotEyeParametersConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const RobotEyeParametersConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static RobotEyeParametersConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &RobotEyeParametersConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const RobotEyeParametersConfig &RobotEyeParametersConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const RobotEyeParametersConfig &RobotEyeParametersConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const RobotEyeParametersConfig &RobotEyeParametersConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<RobotEyeParametersConfig::AbstractParamDescriptionConstPtr> &RobotEyeParametersConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<RobotEyeParametersConfig::AbstractGroupDescriptionConstPtr> &RobotEyeParametersConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const RobotEyeParametersConfigStatics *RobotEyeParametersConfig::__get_statics__()
  {
    const static RobotEyeParametersConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = RobotEyeParametersConfigStatics::get_instance();
    
    return statics;
  }

//#line 17 "../cfg/RobotEyeParameters.cfg"
      const int RobotEyeParameters_stop = 0;
//#line 18 "../cfg/RobotEyeParameters.cfg"
      const int RobotEyeParameters_run = 1;
//#line 19 "../cfg/RobotEyeParameters.cfg"
      const int RobotEyeParameters_pause = 2;
}

#endif // __ROBOTEYEPARAMETERSRECONFIGURATOR_H__
